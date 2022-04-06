#include <iostream> 
void main()
{
	using namespace std;
	const int N = 6, M = 6;
	int A[N][M] = { -1, -2, -3, -4, -5, -6, 1, 2, 3, 4, 5, 6, -1, -2, -3, -4, -5, -6, 1, 2, 3, 4, 5, 6, -1, -2, -3, -4, -5, -6, 1, 2, 3, 4, 5, 6, };
	int sum = 0;

	int i = 0, j = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cout << A[i][j] << " ";
		}
		cout << " " << endl;
	}

	i = 0, j = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (i == j) {
				cout << A[i][j] << " string : " << i << " colum : " << j << endl;
			}
		}
	}

	i = 0, j = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (A[i][j] <= 0) {
				for (j = 0; j < M; j++) {
					sum += A[i][j];
				}
			}
			}
		}
	cout << "sum = " << sum;
	}