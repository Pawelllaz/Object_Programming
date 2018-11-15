#ifndef __VECTOR_H__
#define __VECTOR_H__

template<class C> class vector
{
  C *data;
  unsigned int size;
public:
  class index_out_of_range{};
  explicit vector (int s)
  {
    data = new C[s];
      size = s;
    for (unsigned i = 0; i < size; i++)
        data[i] = C(); //redundant except POD types
  }
   ~vector ()
  {
    delete [] data;
  }
  C& operator[] (unsigned int pos)
  {
    if (pos >= size)
      throw index_out_of_range();
    return data[pos];
  }
  C operator[] (unsigned int pos) const
  {
    if (pos >= size)
      throw index_out_of_range();
    return data[pos];
  }

  vector (const vector<C> & s)
  {
    data = new C[s.size];
    size = s.size;
    try {
    for (unsigned i = 0; i < size; i++)
      data[i] = s.data[i];
    }
    catch(...)
    {
      delete [] data;
      throw;
    }
  }
  
  void swap(vector<C>& s)
  {
    C* t1=s.data;
    unsigned int t2=s.size;
    s.data=data;
    s.size=size;
    data=t1;
    size=t2;
  }
  
  vector<C> & operator= (const vector<C> & s)
  {
    if (this == &s)
      return *this;
    vector<C> n(s);
    swap(n);
    return *this;
  }
  friend ostream & operator<< (ostream & o, const vector<C> & v)
  {
    o << '[';
    for (unsigned i = 0; i < v.size;i++)
      {
	o << v[i];
	if (i != v.size - 1)
	  o << ',';
      };
    o << ']';
    return o;
  }
};
#endif /* __VECTOR_H__ */
