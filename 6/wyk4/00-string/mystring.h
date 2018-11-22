#ifndef __MYSTRING_H__
#define __MYSTRING_H__

class mystring
{
  char *dane;
public:
  mystring ():dane (0)
  {
  };
  ~mystring ()
  {
    delete[]dane;
  };
  mystring (const char *s)
  {
    if (s)
      {
	dane = new char[strlen (s) + 1];
	strcpy (dane, s);
      }
    else
      dane = 0;
  };

  unsigned int length () const
  {
    if (!dane)
      return 0;
    else
      return strlen (dane);
  }

  mystring (const mystring & src)
  {
    if (src.dane)
      {
	dane = new char[strlen (src.dane) + 1];
	strcpy (dane, src.dane);
      }
    else
      dane = 0;
  };
  mystring & operator= (const mystring & src)
  {
    if (this != &src)
      {
	delete[]dane;
	if (src.dane)
	  {
	    dane = new char[strlen (src.dane) + 1];
	    strcpy (dane, src.dane);
	  }
	else
	  dane = 0;
      };
    return *this;
  }

  mystring & operator+= (const mystring & src)
  {
    char *newstr = new char[length () + src.length () + 1];
    if (length ())
      strcpy (newstr, dane);
    else
      newstr[0] = '\0';
    if (src.length ())
      strcat (newstr, src.dane);
    delete[]dane;
    dane = newstr;
    return *this;
  }


  char operator[] (unsigned int i) const
  {
    if (!dane)
      abort ();
    if (i >= strlen (dane))
      abort ();
    return dane[i];
  }
  char &operator[] (unsigned int i)
  {
    if (!dane)
      abort ();
    if (i >= strlen (dane))
      abort ();
    return dane[i];
  }

  friend ostream & operator<< (ostream & o, const mystring & s)
  {
    if (s.dane)
      o << s.dane;
    return o;
  }


};

  inline mystring operator+ (const mystring & s1, const mystring & s2)
  {
    mystring s (s1);
    return s += s2;
  }


#endif /* __MYSTRING_H__ */
