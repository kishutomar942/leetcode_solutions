
#include <iostream>
#include <string>
using namespace std;

bool checkString(string s) {
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == 'b' && s[i + 1] == 'a') {
            return false;
        }
    }

    return true;
}

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    if (checkString(s)) {
        cout << "true";
    }
    else {
        cout << "false";
    }

    return 0;
}
