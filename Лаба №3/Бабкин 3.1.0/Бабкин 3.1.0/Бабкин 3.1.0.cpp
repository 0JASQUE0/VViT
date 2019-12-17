// Подготовил Бабкин Иван Анатольевич, группа 9302, дата начала 08.10.2019, v3.1.0
// u(i) = (-1)^i*(2*i-1)!*x^2i/(2^2i*(i!)^2)   i >= 1
// f(x) = ln2 - ln(1 + sqrt(1 + x^2))		   x^2 < 1

#include <iostream>
#include <math.h>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int i = 1, t = 0;
	double U = -0.0625, S = -0.0625, x, eps;
	ofstream f;

	cout << setprecision(8);

	f.open("ff.txt");

	
	cout << "беск  " << endl;
	cout << "___   " << endl;
	cout << "\\    " << endl;
	cout << "/__ Ui" << endl;
	cout << "i=1   " << endl;
	cout << "\nu(i) = (-1)^i*(2*i-1)!*x^2i/(2^2i*(i!)^2)" << endl;
	cout << "f(x) = ln2 - ln(1 + sqrt(1 + x^2))" << endl;
	cout << "Введите х (-1 ; 1): ";
	cin >> x;


	f << "беск  " << endl;
	f << "___   " << endl;
	f << "\\    " << endl;
	f << "/__ Ui" << endl;
	f << "i=1   " << endl;
	f << "\nu(i) = (-1)^i*(2*i-1)!*x^2i/(2^2i*(i!)^2)" << endl;
	f << "f(x) = ln2 - ln(1 + sqrt(1 + x^2))" << endl;
	f << "Введите х (-1 ; 1): " << x << endl;

	do {
		cout << "Введите eps [0 ; 1e-20): ";
		cin >> eps;
		f << "Введите eps [0 ; 1e-20): " << eps << endl;
		t++;
	} while (((eps <= 0) || (eps > 1e-20)) && (t < 3));


	if ((t == 3) && ((eps <= 0) || (eps > 1e-20))) {
		cout << "Неудача\n";
		f << "Неудача\n";
		return 0;
	}
	else {
		f << "\n  i  |         U          |         S          \n";
		f << "_______________________________________________\n";

		cout << "\n  i  |         U          |         S          \n";
		cout << "_______________________________________________\n";
		while ((fabs(U) >= eps) && (i < 1000)) {
			f << setw(5) << resetiosflags(ios::showpos) << i << "|" << scientific << setiosflags(ios::showpos) << setiosflags(ios::showpoint) << setw(20) << U
				<< "|" << setw(20) << scientific << setiosflags(ios::showpos) << setiosflags(ios::showpoint) << S << endl;
			f << "_______________________________________________\n";

			cout << setw(5) << resetiosflags(ios::showpos) << i << "|" << scientific << setiosflags(ios::showpos) << setiosflags(ios::showpoint) << setw(20) << U 
				 << "|" << setw(20) << scientific << setiosflags(ios::showpos) << setiosflags(ios::showpoint) << S << endl;
			cout << "_______________________________________________\n";
			U = U * (-i * x * x * ((2.0 * i) + 1) / (2.0 * (i + 1.0) * (i + 1.0)));
			S += U;
			i++;
		}
	}

	f << setw(5) << resetiosflags(ios::showpos) << i << "|" << scientific << setiosflags(ios::showpos) << setiosflags(ios::showpoint) << setw(20) << U
		<< "|" << setw(20) << scientific << setiosflags(ios::showpos) << setiosflags(ios::showpoint) << S << endl;
	f << "_______________________________________________\n";

	cout << setw(5) << resetiosflags(ios::showpos) << i << "|" << scientific << setiosflags(ios::showpos) << setiosflags(ios::showpoint) << setw(20) << U
		<< "|" << setw(20) << scientific << setiosflags(ios::showpos) << setiosflags(ios::showpoint) << S << endl;
	cout << "_______________________________________________\n";

	cout << endl << resetiosflags(ios::showpos) << "Количество слагаемых: " << i << endl;
	cout << "Сумма: " << S << endl;
	cout << "f(x) = " << log(2) - log(1 + sqrt(1 + x * x)) << endl;

	f << endl << resetiosflags(ios::showpos) << "Количество слагаемых: " << i << endl;
	f << "Сумма: " << S << endl;
	f << "f(x) = " << log(2) - log(1 + sqrt(1 + x * x)) << endl;

	f.close();

}