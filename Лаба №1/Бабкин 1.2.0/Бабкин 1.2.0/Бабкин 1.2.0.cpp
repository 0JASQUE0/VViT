// Подготовил Бабкин Иван Анатольевич, группа 9302, дата начала 10.09.2019, v1.2.0
// Полином 6: 3214.432x^10 + 324.908x^9 - 23.754
// Полином 1: x^7 + 4x^6 + 2x - 3

#include <iostream>
#include <iomanip>
using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");

	double x, p6, p1, y2, y5, y9, res;

	cout << setprecision(7);

	cout << "Подготовил Бабкин Иван Анатольевич, группа 9302, дата начала 10.09.2019, v1.2.0\n";
	cout << "Полином 6: 3214.432x^10 + 324.908x^9 - 23.754\n";
	cout << "Полином 1: x^7 + 4x^6 + 2x - 3\n";
	cout << "Введите х в пределах (-10^30; -10^-30)v{0}v(10^-30; 10^30)\n";
	cin >> x;

	y2 = x * x;		   //x^2
	y5 = y2 * y2 * x;  //x^5
	y9 = y5 * y2 * y2; //x^9

	p6 = 3214.432 * x + 324.908;
	cout << "Шаг 1 " << setw(20) << p6 << endl;

	p6 = p6 * y9 - 23.754;
	cout << "Шаг 2 " << setw(20) << p6 << endl;

	p1 = x + 4;
	cout << "Шаг 3 " << setw(20) << p1 << endl;

	p1 = p1 * y5 + 2;
	cout << "Шаг 4 " << setw(20) << p1 << endl;

	p1 = p1 * x - 3;
	cout << "Шаг 5 " << setw(20) << p1 << endl;

	res = p6 / p1;

	cout << "Результат при р6/р1 х = " << " равен " << setw(20) << res << endl;
	system("pause");
}