#include <stdio.h>
#include <iostream>
using namespace std;
int f(int x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return x;
	}
	else {
		return x * x / n / (n - 1) * f(x, n - 2);
	}
}
int main()
{
	setlocale(LC_CTYPE, "RU");
	int n;
	cout << "Введите n:";
	cin >> n;
	int  x;
	cout << "Введите x:";
	cin >> x;
	cout << "Ответ:" << f(x, n) << endl;
}