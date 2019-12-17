// ���������� ������ ���� �����������, ������ 9302, ���� ������ 10.09.2019, v1.3.0
// ������� 6: 3214.432x^10 + 324.908x^9 - 23.754
// ������� 1: x^7 + 4x^6 + 2x - 3

#include <iostream>
#include <stdio.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");

	double x, p6, p1, y5, y9, res;

	printf ("���������� ������ ���� �����������, ������ 9302, ���� ������ 10.09.2019, v1.3.0\n");
	printf ("������� 6: 3214.432x^10 + 324.908x^9 - 23.754\n");
	printf ("������� 1: x^7 + 4x^6 + 2x - 3\n");
	printf ("������� � � �������� (-10^3; -10^-3)v{0}v(10^-3; 10^3)\n");
	scanf_s ("%lf", &x);

	y5 = x * x * x * x * x; //x^5
	y9 = x * x * x * x * x * x * x * x * x; //x^9

	p6 = 3214.432 * x + 324.908;
	printf ("��� 1 %20.3lf %c", p6, '\n');

	p6 = p6 * y9 - 23.754;
	printf ("��� 2 %20.3lf %c", p6, '\n');

	p1 = x + 4;
	printf ("��� 3 %20.3lf %c", p1, '\n');

	p1 = p1 * y5 + 2;
	printf ("��� 4 %20.3lf %c", p1, '\n');

	p1 = p1 * x - 3;
	printf ("��� 5 %20.3lf %c", p1, '\n');

	res = p6 / p1;

	printf("��������� ��� �6/�1 � = %lf %s %20.3lf %c", x, " ����� ", res, '\n');

	system("pause");
}