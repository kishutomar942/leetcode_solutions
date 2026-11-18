
#include <iostream>
#include <string>
using namespace std;

int minChanges(string s) {
    int count = 0;

    for (int i = 0; i < s.length(); i += 2) {
        if (s[i] != s[i + 1]) {
            count++;
        }
    }

    return count;
}

int main() {
    string s = "1001";

    cout << "Minimum changes: "
         << minChanges(s);

    return 0;
}
