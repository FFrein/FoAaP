#include <iostream>
#include <ctime>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 10; 
	int i, A[N], min = N, max = 0, number_max, number_min, peremen=0, k=0, k1=0;
	int rmx = 20; 

	srand((unsigned)time(NULL));
	for (i = 0; i < N; i++)
	{
		A[i] = rand() % rmx;
	}

	for (i = 0; i < N; i++) {
		if(A[i] < min){
			min = A[i];
			number_min = i;
		}
		if (A[i] > max){
			max = A[i];
			number_max = i;
		}
	}

	cout << "number min = " << number_min << "number max = " << number_max << endl;
	cout << "min = " << min << " max = " << max << endl;
	for (i = 0; i < N; i++) {
		cout << A[i] << endl;
	}
	cout << "Было" << endl;

	/*определениа точки начала отсчёта*/
	if (number_max - number_min < 0) {
		k = number_max;
	}
	else {
		k = number_min;
	}
	/*перемещение значений*/
	for (i = 0; i < N; i++) {
		if (number_max - number_min < 0) {
			peremen = A[k + 1];
			A[k + 1] = A[number_min - k1];
			A[number_min - k1] = peremen;
			k1 += 1;
			k += 1;
		}
		else {
			peremen = A[k - 1];
			A[k - 1] = A[number_max + k1];
			A[number_max + k1] = peremen;
			k1 += 1;
			k += 1;
		}
		/*ограничегие границ*/
		if (k1 == number_max || k == number_min || k == number_max || k1 == number_min) {
			i = N;
		}
	}

	for (i = 0; i < N; i++) {
		cout << A[i] << endl;
	}
	
	return 0;
}