#include <iostream>

using namespace std;

int rekursia(int n, int shag, int count, int result = 0) {
	if (count < n) {
		result += shag;
		count++;
		return rekursia(n, shag, count, result);
	}
	if (count == n) {
		result += shag;
		return result;
	}
}

int main() {
	int n, shag = 25, counter = 0, result;
	cout << "Input N:";
	cin >> n;
	result = rekursia(n, shag, counter);
	cout << "Result letter:" << (char)result;
	return 0;
}