// ���������� ������ ���� �����������, ������ 9302, ���� ������ 10.09.2019, v1.2.0
// ������� 6: 3214.432x^10 + 324.908x^9 - 23.754
// ������� 1: x^7 + 4x^6 + 2x - 3

#include <iostream>
#include <iomanip>
using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");

	double x, p6, p1, y2, y5, y9, res;

	cout << setprecision(7);

	cout << "���������� ������ ���� �����������, ������ 9302, ���� ������ 10.09.2019, v1.2.0\n";
	cout << "������� 6: 3214.432x^10 + 324.908x^9 - 23.754\n";
	cout << "������� 1: x^7 + 4x^6 + 2x - 3\n";
	cout << "������� � � �������� (-10^30; -10^-30)v{0}v(10^-30; 10^30)\n";
	cin >> x;

	y2 = x * x;		   //x^2
	y5 = y2 * y2 * x;  //x^5
	y9 = y5 * y2 * y2; //x^9

	p6 = 3214.432 * x + 324.908;
	cout << "��� 1 " << setw(20) << p6 << endl;

	p6 = p6 * y9 - 23.754;
	cout << "��� 2 " << setw(20) << p6 << endl;

	p1 = x + 4;
	cout << "��� 3 " << setw(20) << p1 << endl;

	p1 = p1 * y5 + 2;
	cout << "��� 4 " << setw(20) << p1 << endl;

	p1 = p1 * x - 3;
	cout << "��� 5 " << setw(20) << p1 << endl;

	res = p6 / p1;

	cout << "��������� ��� �6/�1 � = " << " ����� " << setw(20) << res << endl;
	system("pause");
}