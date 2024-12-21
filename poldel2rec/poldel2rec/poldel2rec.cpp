#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;
double eps = 0.0001;
double f(double x){
    return x - (1 / (3 + sin(3.6 * x)));
}
double del(double a, double b, double eps){
    double x = (a + b) / 2;
    if ((abs(f(a) - f(b)) <= eps)){
        if (abs(f(x)) <= eps){
            return (a + b) / 2;
        }
    }
    if (f(a) * f(x) <= 0.0){
        del(a, x, eps);
    }
    else{
        del(x, b, eps);
    }
}



int main(){
    setlocale(LC_ALL, "russian");
    double a, b;
    cout << "Введите интервал: ";
    cin >> a;
    cin >> b;
    cout << del(a, b, eps);
    return 0;
}