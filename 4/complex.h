#ifndef __Complex_H__
#define __Complex_H__
#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
private:
  double Real, Imag;
public:
  Complex(double re=0, double im=0)
  {
    this->Real=re;
    this->Imag=im;
  }
  Complex & operator= (const Complex & s)
  {
    Real = s.Real;
    Imag = s.Imag;
    return *this;
  };

  Complex operator- () const
  {
    return Complex(-Real,-Imag);
  };

  Complex & operator= (double co)
  {
    Real = co;
    Imag = 0;
    return *this;
  };

  Complex operator+ (const Complex& co) const
  {
    Complex n;
    n.Real = this->Real + co.Real;
    n.Imag = this->Imag + co.Imag;
    return n;
  };


  Complex & operator-= (Complex co)
  {
    Real -= co.Real;
    Imag -= co.Imag;
    return *this;
  };
  Complex operator/ (const Complex& co) const 
  {
    Complex n;
    double re;
    re = this->Real * co.Real + co.Imag * this->Imag;
    n.Real = (this->Real * co.Real + this->Imag * co.Imag)/re;
    n.Imag = (co.Real * this->Imag - this->Real * co.Imag)/re;
    return n;
  }
  Complex & operator/= (Complex co)
  {
    Complex n;
    double re = this->Real * co.Real + co.Imag * this->Imag;
    n.Real = (this->Real * co.Real + this->Imag * co.Imag)/re;
    n.Imag = (co.Real * this->Imag - this->Real * co.Imag)/re;
    *this=n;
    return *this;	
  }
  double abs()
  {
    double abs=sqrt((this->Real*this->Real)+(this->Imag*this->Imag));
    return abs;
  }
  double phase()
  {
    double ph=atan2(this->Real,this->Imag);
    return ph;
  }
  Complex conj()
  {
    return Complex(this->Real,-this->Imag);
  }
  friend Complex operator- (Complex, Complex);
  friend ostream & operator << (ostream & s, const Complex & c)
  {
    s << "(" << c.Real << "," << c.Imag << ")";
    return s;
  };
};

inline Complex
operator - (Complex s1, Complex s2)
{
  Complex n (s1);
  return n -= s2;
}

#endif /* __Complex_H__ */
