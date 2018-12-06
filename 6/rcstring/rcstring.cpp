#include "rcstring.h"

int main()
{
	rcstring a, b, c;
	a = "10";
	b = "ala ma kota";
	cout << a << " " << b << endl; // 10 ala ma ma kota
	c = a + b;
	cout << c << endl; // 10ala ma kota
	c = a + rcstring(" ") + b;
	cout << c << endl; //10 ala ma kota
	rcstring d("a");
	cout << d << endl; //a
	d += "ula";
	cout << d << endl; //aula
	d += "15";
	cout << d << endl; //aula15
	cout << d[3] << endl; //a
	d[3] = 'b';
	cout << d << endl; //aulb15
	d[2] = d[1] = d[0];
	cout << d << endl; //aaab15

	// funkcje dopisane

	rcstring e, f, g, h;
	// atoi	
	e = "123";
	cout << e.atoi() << endl;
	// toLower
	f = "dUzE Na MaLe";
	rcstring F = f;
	f.toLower();
	cout << f << endl;
	cout << "DUZE: " << F << endl;
	// Left
	g = "ala ma kota i psa";
	h = g.Left(3);
	cout << "oryginal: " << g << "\nLeft(3): " << h <<endl;
	cout << g <<endl;
	return 0;
}
