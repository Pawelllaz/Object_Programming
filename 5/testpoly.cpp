#include <iostream>
using namespace std;
#include "poly.h"


int main(void)
{
  poly P1;				//Declare object representing polynomial P1
  P1[3] = 2; P1[1] = 3.6; P1[0] = 7;	//Specify coefficients of P1 = 2x^3 + 3.6x + 7
  
  poly P2 = 5;				//Declare object representing polynomial P2 = 5
  P2[1] = 3; P2[2] = 6; P2[4] = 1;	//Specify additional coefficients of P2 = x^4 + 6x^2 + 3x + 5
  
  cout << "Polynomial P1: " << P1 << endl;	//Print P1 	
  cout << "Polynomial P2: " << P2 << endl;	//Print P2
  
  poly P3 = P1 + P2;						//Add P1 and P2 	
  cout << "Sum of polynomials P1 and P2: " << P3 << endl;	//Print sum of P1 and P2
  
  P3 = P1 * P2;							//Multiply P1 by P2 	
  cout << "Product of polynomials P1 and P2: " << P3 << endl;	//Print product of P1 and P2

  P3 = 2 * P1;							//Multiply P1 by 2 	
  cout << "Polynomial P1 multiplied by 2: " << P3 << endl;	//Print product of P1 and 2
  
  double val = P1(3.14);						//Calculate the value of P1 at point 3.14
  cout << "Value of polynomial P1 at point 3.14: " << val << endl;	//Print the value of P1 at point 3.14
};
