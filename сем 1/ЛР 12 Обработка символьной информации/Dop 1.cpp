#include <iostream>
#include <string>
using namespace std;

int main() {
	cout << "Input 3 words" << endl;
	string str1 = "";
	string str2 = "";
	string str3 = "";

	cin >> str1 >> str2 >> str3;
	cout << "Input symbl" << endl;
	char end;
	cin >> end;



	if (str1[(str1.size() - 1)] == end)
	{
		cout << str1;
	}
	if (str2[(str2.size() - 1)] == end)
	{
		cout << endl << str2;
	}
	if (str3[(str3.size() - 1)] == end)
	{
		cout << endl << str3;
	}

	return 0;
}