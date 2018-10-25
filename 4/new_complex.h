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
Complex & operator= (const Complex & s);	
Complex operator- ()const;
Complex & operator= (double co);
Coplex operator+ (double Complex& co) const
Complex & operator-=(Complex co);


};


#endif /* __Complex_H__ */
