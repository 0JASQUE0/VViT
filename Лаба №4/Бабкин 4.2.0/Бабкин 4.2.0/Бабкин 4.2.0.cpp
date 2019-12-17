// Подготовил Бабкин Иван Анатольевич, группа 9302, дата начала 26.10.2019, v4.2.0
// Задана последовательность целых чисел a1, a2,..., an.
// Найти тройки чисел ai-1, ai, ai+1, удовлетварающих условию:
// ai <= (ai-1 + ai+1) / 2

#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int i, z = 0;
	float s;
	float* pa;

	fstream fin;

	fin.open("fin.txt", ios::in);

	if (fin.bad()) {
		cout << "Error";
	}
	else {
	}

	fin >> s;

	while (!fin.eof()) {
		fin >> s;
		z++;
	}


	fin.seekg(3);

	pa = new float[z];

	for (i = 0; i < z; i++) {
		fin >> *(pa + i);
		if (fin.eof()) {
			z = i + 1;
			break;
		}
	}

	fin.close();

	fin.open("fout.txt", ios::out);


	fin << "Подготовил Бабкин Иван Анатольевич, группа 9302, дата начала 26.10.2019, v4.2.0\n";
	fin << "Задана последовательность целых чисел a1, a2,..., an.\n";
	fin << "Найти тройки чисел ai-1, ai, ai+1, удовлетварающих условию:\n";
	fin << "ai <= (ai-1 + ai+1) / 2\n";

	fin << "Количество элементов в массиве z: " << z << endl;

	fin << "Исходный массив: \n";

	for (i = 0; i < z; i++) {
		fin << *(pa + i) << " ";
	}

	fin << endl;

	for (i = 1; i < z - 1; i++) {
		if (*(pa + i) <= ((*(pa + i - 1) + *(pa + i + 1)) / 2))
			fin << *(pa + i) << " ";
	}
	fin.close();

	delete[]pa;

	return 0;
}