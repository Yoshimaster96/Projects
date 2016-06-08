#include <iostream>
#include <complex>

using namespace std;

int main()
{
	float x = 0.0, y = 0.0;
	cout << "Please enter x\n";
	cin >> x;
	cout << "Please enter y\n";
	cin >> y;
	complex<float> z (x,y);
	cout << "real(z) = " << real(z) << "\n";
	cout << "imag(z) = " << imag(z) << "\n";
	cout << "abs(z) = " << abs(z) << "\n";
	cout << "arg(z) = " << arg(z) << "\n";
	cout << "norm(z) = " << norm(z) << "\n";
	cout << "conj(z) = " << conj(z) << "\n";
	cout << "sin(z) = " << sin(z) << "\n";
	cout << "sinh(z) = " << sinh(z) << "\n";
	cout << "cos(z) = " << cos(z) << "\n";
	cout << "cosh(z) = " << cosh(z) << "\n";
	cout << "exp(z) = " << exp(z) << "\n";
	cout << "log(z) = " << log(z) << "\n";
	cout << "sqrt(z) = " << sqrt(z) << "\n";
	return 0;
}
