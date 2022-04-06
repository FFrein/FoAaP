#include <iostream> 
/*Представим трёхмерный массив в виде прямоуголького 
параллелепипеда.
Получаемые проекции будут севой стороной, нижней стороной, 
задней стороной*/
void main()
{
	using namespace std;
	const int Z = 4, X = 5, Y = 3, N = Z, M = X, F = Y;
	int B1[F][M], B2[F][M], B3[F][M], A[N][F][M] = {
	1, 1, 1, 1, 1,
	1, 1, 1, 1, 1,
	1, 1, 1, 1, 1,

	2, 2, 2, 2, 2,
	2, 2, 2, 2, 2,
	2, 2, 2, 2, 2,

	1, 1, 1, 1, 1,
	1, 1, 1, 1, 1,
	1, 1, 1, 1, 1,

	2, 2, 2, 2, 2,
	2, 2, 2, 2, 2,
	2, 2, 2, 2, 2,
	};

	int i, j, k;
	for (i = 0; i < N; i++) {
		for (j = 0; j < F; j++) {
			for (k = 0; k < M; k++) {
				cout << A[i][j][k] << " ";
			}
			cout << " " << endl;
		}
		cout << " " << endl;
	}

	cout << "Left" << endl;
	/*Цикл поиска левой стороны*/
	for (i = 0; i < Z; i++) {
		for (j = 0; j < Y; j++) {
			for (k = 0; k < X; k++) {
				if (k == 0) {
					B1[j][k] = A[i][j][k];
					cout << A[i][j][k] << " ";
				}
			}
		}
		cout << " " << endl;
	}

	cout << "Down" << endl;

	/*Цикл поиска нижней стороны*/
	for (i = 0; i < Z; i++) {
		for (j = 0; j < Y; j++) {
			for (k = 0; k < X; k++) {
				if (j == (Y - 1)) {
					B2[j][k] = A[i][j][k];
					cout << A[i][j][k] << " ";
				}
			}
		}
		cout << " " << endl;
	}
	cout << "Back" << endl;

	/*Цикл поиска задней стороны*/
	for (i = 0; i < Z; i++) {
		for (j = 0; j < Y; j++) {
			for (k = 0; k < X; k++) {
				if (i == (Z - 1)) {
					B3[j][k] = A[i][j][k];
				}
			}
		}

	}
	for (j = 0; j < Y; j++) {
		for (k = 0; k < X; k++) {
			cout << B3[j][k] << " ";
		}
		cout << " " << endl;
	}
}
