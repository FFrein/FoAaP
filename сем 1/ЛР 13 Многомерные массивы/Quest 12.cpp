#include <iostream> 
/*���� ������������� ������� A(N, M). ��������� ����� � 
������������ �������� ������������� ��������� �������, 
��������������� ������� | a(i j)�| < i.*/
/*������� �� �������, ����� ������������ ����� ������ ������ ������*/
void main()
{
	using namespace std;
	const int N = 2, M = 5;
	int A[N][M] = { -1, -2, -3, -4, -5, 1, 2, 3, 4, 5 };
	int proizvedenie = 1;

	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (A[i][j] % 2 != 0 && A[i][j] < 0) {
				proizvedenie *= A[i][j];
			}
			cout << "\n a[" << i << "," <<
				j << "] =" << A[i][j];
		}
	}
	cout << "\n" << proizvedenie;
}