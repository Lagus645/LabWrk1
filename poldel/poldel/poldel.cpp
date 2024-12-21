#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

double F(double x) {
	return x - (1 / (3 + sin(3.6 * x)));
}

double Findx(double (*f)(double), double a, double b, double eps) {
	double c;
	while ((b - a) / 2 > eps) {
		c = (a + b) / 2;
		if ((f(a) * f(c)) > 0) a = c;
		else b = c;
	}
	return c;
}
int main() {
	setlocale(LC_ALL, "russian");
	double a, b, eps, x;
	cout << "Введите интервал: ";
	cin >> a;
	cin >> b;
	if (F(a) * F(b) > 0) {
		cout << "Неправильный интервал\n";
		return 0;
	}
	cout << "Погрешность: ";
	cin >> eps;
	x = Findx(F, a, b, eps);
	cout << "x = " << x << endl;
	return 0;
}