#include <iostream>
#include <clocale>
#include <math.h>
using namespace std;


const int N = 10;
//Функция для полинома:
double F(double x) {
	return x-(1/(3+sin(3.6*x)));
}

//Функция поиска корня:
double findx(double (*f)(double), double x0, int n) {
	double x = x0, df, e;
	cout << "Введите e: ";
	cin >> e;
	df = (f(x + e) - f(x)) / e;
	for (int i = 1; i <= n; i++) {
		x = x - f(x) / df;
		cout << x << endl;
	}
	return x;
}
int main() {
	setlocale(LC_ALL, "russian");
	//Начальное приближение и корень:
	double x0, x;
	cout << "Первоначальный x0 = ";
	cin >> x0;
	//Поиск решения:
	x = findx(F, x0, N);
	cout << "x = " << x << endl;
	return 0;
}