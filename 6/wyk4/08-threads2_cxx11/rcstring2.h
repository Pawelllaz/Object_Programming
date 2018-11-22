#ifndef __RCSTRING_H__
#define __RCSTRING_H__
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <mutex>
using namespace std;

class rcstring
{
  struct rctext;
  rctext *data;
public:
    class Range
  {
  };
  class Cref;
  rcstring ();
  rcstring (const char *);
  rcstring (const rcstring &);
  ~rcstring ();
  rcstring & operator= (const char *);
  rcstring & operator= (const rcstring &);
  rcstring & operator+= (const rcstring &);
  rcstring operator+ (const rcstring &) const;
  friend ostream & operator<< (ostream &, const rcstring &);
  void check (unsigned int i) const;
  char read (unsigned int i) const;
  void write (unsigned int i, char c);
  char operator[] (unsigned int i) const;
  Cref operator[] (unsigned int i);
  unsigned int getRefCount ();
};

struct rcstring::rctext
{
  char *s;
  unsigned int size;
  unsigned int n;
  std::mutex mutex;
  
  rctext (unsigned int nsize, const char *p)
  {
    n = 1;
    size = nsize;
    s = new char[size + 1];
    strncpy (s, p, size);
    s[size] = '\0';
  };
  ~rctext ()
  {
    delete[]s;
  };
  unsigned int AtomicRead()
  {
    unsigned int retval;
    mutex.lock();
    retval = n;
    mutex.unlock();
    return retval;
  };
  
  unsigned int AtomicIncrement()
  {
    mutex.lock();
    unsigned int retval=++n;
    mutex.unlock();
    return retval;
  };

  unsigned int AtomicDecrement()
  {
    mutex.lock();
    unsigned int retval=--n;
    mutex.unlock();
    return retval;
  };

  void assign (unsigned int nsize, const char *p)
  {
    if (size != nsize)
      {
	char *ns = new char[size + 1];
	size = nsize;
	strncpy (ns, p, size);
	delete[]s;
	size = nsize;
	s = ns;
      }
    else
      strncpy (s, p, size);
    s[size] = '\0';
  }

private:
  rctext (const rctext &);
  rctext & operator= (const rctext &);
};

class
  rcstring::Cref
{
  friend class rcstring;
  rcstring & s;
  int i;
  Cref (rcstring & ss, unsigned int ii): s (ss), i (ii) {};
public:
  operator  char () const
  {
    return s.read (i);
  }
  rcstring::Cref &
  operator = (char c)
  {
    s.write (i, c);
    return *this;
  };
  rcstring::Cref & operator = (const Cref & ref)
  {
    return operator= ((char) ref);
  };
};
inline
rcstring::rcstring ()
{
  data = new rctext (0, "");
}

inline
rcstring::rcstring (const rcstring & x)
{
  x.data->AtomicIncrement();
  data = x.data;
}

inline
rcstring::~rcstring ()
{
  if(data->AtomicDecrement()==0)
    delete data;
}

rcstring & rcstring::operator= (const rcstring & x)
{
  rctext* olddata=data;
  x.data->AtomicIncrement();
  data = x.data;
  if(olddata->AtomicDecrement()==0)
    delete olddata;
  return *this;
}

rcstring::rcstring (const char *s)
{
  data = new rctext (strlen (s), s);
}

rcstring & rcstring::operator= (const char *s)
{
  if (data->AtomicRead() == 1)
    data->assign (strlen (s), s);
  else
    {
      rctext* olddata=data;
      data = new rctext (strlen (s), s);
      if(olddata->AtomicDecrement()==0)
        delete olddata;
    };
  return *this;
}

ostream & operator << (ostream & o, const rcstring & s)
{
  return o << s.data->s;
}

rcstring & rcstring::operator+= (const rcstring & s)
{
  int  newsize =  data->size +  s.data->size;
  rctext * newdata = new  rctext (newsize, data->s);
  strcat (newdata->s, s.data->s);
  rctext* olddata=data;
  data=newdata;
  if(olddata->AtomicDecrement()==0)
    delete olddata;
  return *this;
}

rcstring
rcstring::operator+ (const rcstring & s) const
{
  return rcstring (*this) += s;
}

inline void
rcstring::check (unsigned int i) const
{
  if (data->size <= i)
    throw Range ();
}

inline char
rcstring::read (unsigned int i) const
{
  return data->s[i];
}

inline void
rcstring::write (unsigned int i, char c)
{
  if (data->AtomicRead() > 1)
  {
    rctext* newdata=new rctext(data->size,data->s);
    rctext* olddata=data;
    data=newdata;
    if(olddata->AtomicDecrement() == 0)
      delete olddata;
  }
  data->s[i] = c;
}

char
rcstring::operator[] (unsigned int i)  const
{
  check (i);
  return data->s[i];
}

rcstring::Cref rcstring::operator[](unsigned int i)
{
  check (i);
  return Cref (*this, i);
}


unsigned int
rcstring::getRefCount ()
{
  return data->AtomicRead();;
}

#endif /* __RCSTRING_H__ */
