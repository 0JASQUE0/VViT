// Подготовил Бабкин Иван Анатольевич, группа 9302, дата начала 26.10.2019, v4.1.0
// Задана последовательность целых чисел a1, a2,..., an.
// Найти тройки чисел ai-1, ai, ai+1, удовлетварающих условию:
// ai <= (ai-1 + ai+1) / 2

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	const int n = 50;
	float a[n];
	int i, z;

	fstream fin;

	fin.open("fin.txt", ios::in);

	if (fin.bad()) {
		cout << "Error";
	}
	else {
		fin >> z;
		if (z < 0) z = 0;
		else if (z > n) z = n;
	}

	for (i = 0; i < z; i++) {
		fin >> a[i];
		if (fin.eof()) {
			z = i + 1;
			break;
		}
	}

	fin.close();

	fin.open("fout.txt", ios::out);


	fin << "Подготовил Бабкин Иван Анатольевич, группа 9302, дата начала 26.10.2019, v4.1.0\n";
	fin << "Задана последовательность целых чисел a1, a2,..., an.\n";
	fin << "Найти тройки чисел ai-1, ai, ai+1, удовлетворяющих условию:\n";
	fin << "ai <= (ai-1 + ai+1) / 2\n";

	fin << "Количество элементов в массиве z: " << z << endl;
	fin << "Исходный массив: \n";

	for (i = 0; i < z; i++) {
		fin << a[i] << " ";
	}

	fin << endl;

	for (i = 1; i < z - 1; i++) {
		if (a[i] <= ((a[i - 1] + a[i + 1]) / 2))
			fin << a[i] << " ";
	}
	fin.close();

	return 0;
}