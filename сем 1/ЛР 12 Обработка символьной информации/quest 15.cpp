#include <iostream>
#include <string>
int main() {
    using namespace std;
    string s;
    cout << "Input string: ";
    cin >> s;
    char c;
    cout << "Input 'delet' symbl: ";
    cin >> c;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c) {
            s.erase(i, 1); i--;
        }
    }
    cout << s;
}