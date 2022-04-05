#include <iostream>

int main()
{
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	int a, b;
	int c;
	cout << "Выберите операцию : " << endl << "1) *" << endl << "2) /" << endl	<< "3) +" << endl	<< "4)-" << endl	<< "5) %" << endl;
	cin >> c;
	cout << "Выберите раздельно числа a и b : ";
	cin >> a;
	cin >> b;

	switch (c)
	{
		case 1 :{
			a = a * b;
			break;
		}
		case 2 : {
			a = a / b;
			break;
		}
		case 3: {
			a = a + b;
			break;
		}
		case 4: {
			a = a - b;
			break;
		}
		case 5: {
			a = a % b;
			break;
		}
	}
	cout << "Ответ = " << a;
	return 0;
}