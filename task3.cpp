#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string s;
    cout << "Введите строку: ";
    getline(cin, s);

    string result;
    int depth = 0;

    for (char c : s) {
        if (c == '(') {
            depth++;
            if (depth == 1) result += ' ';
        } else if (c == ')') {
            depth--;
        } else if (depth == 0) {
            result += c;
        }
    }

    cout << result << endl;
    return 0;
}