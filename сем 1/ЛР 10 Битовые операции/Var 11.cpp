#include <iostream> 
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");

	int A, B, p, n;
	char tmp[33];

	cout << "������� 11\n\n";
	cout << "������� �1" << endl;
	cout << "������� �����: ";
	cin >> A;

	if ((A & 15) == 0) {
		cout << "����� ������ 16\n\n";
	}
	else {
		cout << "����� �� ������ 16\n\n";
	}

	cout << "������� �2\n";
	cout << "�: "; cin >> A;
	cout << "������� ��������� ������� p: "; cin >> p;
	cout << "������� ���������� ������������ ����� n: "; cin >> n;

	if (p == 0) {
		cout << "p �� ����� ��������� ����!\n\n";
	}
	else {
		_itoa_s(A, tmp, 2);
		cout << tmp << " - ";

		int b = A - ((A >> p) << p);
		int c = (A >> (p + n)) << (p + n);
		int rev = ((A - c - b) >> p);
		int xor_num = 0;

		for (int i = 0; i < n; i++) {
			xor_num += pow(2, i);
		}

		int k = xor_num ^ rev;
		_itoa_s(k, tmp, 2);
		cout << tmp << endl;

		cout << "�: "; cin >> B;
		cout << "������� ��������� ������� p: "; cin >> p;

		if (p == 0) {
			cout << "��������� ������� �� ����� ���� ������ ����!";
		}
		else {
			_itoa_s(B, tmp, 2);
			cout << tmp << endl;
			b = B - ((B >> (p - 1)) << (p - 1));
			c = (B >> (p - 1 + n)) << (p - 1 + n);

			c >>= (p - 1);
			c += k;
			c <<= (p - 1);
			c += b;

			_itoa_s(c, tmp, 2);
			cout << tmp << "\n\n";
		}
	}
	return 0;
}