#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <string.h>
#include <iostream>

class string
{
  char *data;
  unsigned len;
public:
  string ():data (0), len(0)
  {
  };
  ~string ()
  {
    delete[]data;
  };
  string (const char *s)
  {
    if (s)
      {
        len=strlen(s);
	data = new char[len + 1];
	strcpy (data, s);
      }
    else
    {
      data = 0;
      len = 0;
    }
  };

  string (const string & src)
  {
    if (src.data)
      {
	data = new char[src.len + 1];
	len = src.len;
	strcpy (data, src.data);
      }
    else
    {
      data = 0;
      len = 0;
    }
  };
  string & operator= (const string & src)
  {
    if (this != &src)
      {
	delete[]data;
	if (src.data)
	  {
	    data = new char[src.len + 1];
	    strcpy (data, src.data);
	  }
	else
	{
	  data = 0;
	  len = 0;
	}
      };
    return *this;
  }
};


#endif /* __string_H__ */
