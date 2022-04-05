#include <iostream>
int main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	double P, Q;
	cout << "введите P = ";
	cin >> P;
	cout << "Введите значение Q = " << endl;
	cin >> Q;
	for (int d = 1; P <= Q; d++) {
		P = P + P*0.03;
		cout << "День " << d << endl;
		cout << "значение " << P << endl;
	}
	return 0;
}