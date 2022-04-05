#include <iostream>

using namespace std;

int main()
{
	float V1, V2, L1, L2;
	cin >> V1;
	cin >> V2;
	cin >> L1;
	cin >> L2;
	for (int i = 1; i <= 12; i++) {
		L1 = L1 + (L2 / 2);
		L2 = L2 / 2;
		if (L1 >= V1) {
			L1 = V1;
		}
		L2 = L2 + (L1 / 2);
		L1 = L1 / 2;
		if (L2 >= V2) {
			L2 = V2;
		}
		i = i + 1;
	}
	cout << "L1 = " << L1 << " L2 = " << L2;
}
