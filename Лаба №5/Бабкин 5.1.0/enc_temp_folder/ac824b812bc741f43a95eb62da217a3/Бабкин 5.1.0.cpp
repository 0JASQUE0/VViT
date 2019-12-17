#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void input(float**& A, int& N, int& m) {
	char c = ' ';
	fstream f;
	int icolumns = 0, ilines = 0;
	f.open("input.txt", ios::in);
	if (!f.is_open()) cout << "Файл не найден";
	else {
		f >> N;
		f >> m;
		if (N != 0 && N != 1) {
			A = new float* [2];
			for (int i = 0; i < N; i++)
				A[i] = new float[N];
			while (!f.eof() && ilines < N) {
				while (c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9' && c != '+' && c != '-' && c != '\n' && !f.eof()) {
					f >> c >> noskipws;
				}
				if (c != '\n') {
					if (icolumns < N) {
						f.unget();
						f >> A[ilines][icolumns];
						icolumns++;
					}
					c = ' ';
				}
				else {
					if (ilines < N) {
						if (icolumns < N) N = icolumns;
						icolumns = 0;
						ilines++;
					}
					c = ' ';
				}
			}
			if (ilines + 1 < N) N = ilines + 1;
		}
	}
	f.close();
}

void control(float** A, int N, int m) {
	fstream f;
	f.open("output.txt", ios::out);
	f << "Контрольный вывод:\n" << N << endl << m << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) f << A[i][j] << " ";
		f << endl;
	}
	f.close();
}

void check(float& value, float& max) {
	if (value >= max) {
		max = value;
	}
}

void printf(fstream& f, float& max) {
	setlocale(LC_ALL, "rus");
	f << "Максимальный член = " << max;
}

void work(float**  &A, int& N, int& m) {
	fstream f;
	float value, max;
	f.open("output.txt", ios::app);
	int N05, i, j;
	N05 = (N / 2) + (N % 2);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j && i >= m - 1) {
				value = A[i][j];
				check(value, max);
			}
			if (i == N05 - 1 && j >= m - 1 && j <= N05 - 1) {
				value = A[i][j];
				check(value, max);
			}
			
			if (j == N05 - 1 && i >= m - 1 && i <= N05 - 1) {
				value = A[i][j];
				check(value, max);
			}
		}
	}
	printf(f, max);
	f.close();
}

int main() {
	setlocale(LC_ALL, "rus");
	int lines = 0, columns = 0, N = 0, m = 0, ilines = 0, icolumns = 0;
	float** A;
	A = new float* [1];
	for (int i = 0; i < 1; i++)
		A[i] = new float[1];
	input(A, N, m);
	if (N != 0 && N != 1) {
		control(A, N, m);
		work(A, N, m);
	}
	for (int i = 0; i < N; i++)
		delete A[i];
	delete[]A;
	cout << "Результат работы ожидает Вас в output.txt";
	return 0;
}