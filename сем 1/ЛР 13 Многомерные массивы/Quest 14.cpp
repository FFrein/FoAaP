#include <iostream> 
/*���� ������� �(N, N) � ����� ����� m. ������������� ������� �� 
�������: ������ � ������� M ������� �������� � ������� M, � 
������� � ������� M ������� ������� � ������� M*/

void main()
{
	using namespace std;
	const int N = 4;
	int M = 1; /* ��������� ����� ������ �� 0*/
	int A[N][N] = { 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4};

	int N2 = N;

	int i = 0, j = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cout << A[i][j] << " ";
		}
		cout << " " << endl;
	}
	
	cout << " " << endl;

	j = 0;
	
	int swap1, swap2;
	for (i = 0; i < N; i++) {
		swap1 = A[i][M];
		swap2 = A[M][j];
		A[i][M] = swap2;
		A[M][j] = swap1;
		j++;
	}


	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cout << A[i][j] << " ";
		}
		cout << " " << endl;
	}
}