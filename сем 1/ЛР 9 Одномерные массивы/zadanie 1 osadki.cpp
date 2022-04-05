#include <iostream>
#include <ctime>

int main()
{
	setlocale(LC_CTYPE, "Russian");
	using namespace std;
	const int N = 365; /*кол дней*/
	int i, A[N], osadki=0, max_osadki=0, days=1, data=0, week=0;
	int rmx = 99; /*число осадков макс*/

	srand((unsigned)time(NULL));
	for (i = 0; i < N; i++)
	{
		A[i] = rand() % rmx;
	}
	for (i = 0; i < N; i++) {
		osadki += A[i];
		days += 1;
		if (days == 7) {
			week += 1;
			if (osadki > max_osadki) {
				max_osadki = osadki;
				data = week;
			}
			days = 0;
			osadki = 0;
		}
	}
	cout << max_osadki << endl;
	cout << data;
	return 0;
}
