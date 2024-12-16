#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

double F(double x0){
	return x0 - 1 / (3 + sin(3.6 * x0));
}

double F1(double x){
	return 1 / (3 + sin(3.6 * x));
}

double F2(double x){
	return -(cos(3.6 * x) * 3.6) / pow(3 + sin(3.6 * x), 2);
}

int main(){
	setlocale(LC_ALL, "russian");
	double a, b, e, x0, x1;
	cout << "Введите границы a, b: ";
	cin >> a >> b;
	int f = 1;
	cout << "Введите e:" << endl;
	cin >> e;

	if (F2(a) < 1) //	проверяем условие сходоимости инаходим первое приближение к корню
	{
		x0 = a;
	}
	else if (F2(b) < 1)
	{
		x0 = b;
	}
	else
	{
		cout << "Условие сходимости невыполнено";
		f = 0;
	}

	if (f == 1)
	{
		x1 = F1(x0); // следующее приближение к корню
		cout << x1 << endl;
		while (abs((x0 - x1)) > e){
			x0 = x1;
			x1 = F1(x0);
			cout << x1 << endl;
		}
		cout << "x = " << x1;
	}
	return 0;
}
