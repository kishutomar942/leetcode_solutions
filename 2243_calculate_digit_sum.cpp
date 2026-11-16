
#include <iostream>
#include <string>
using namespace std;

string digitSum(string s, int k) {

    while (s.length() > k) {

        string ans = "";

        for (int i = 0; i < s.length(); i += k) {

            int sum = 0;

            for (int j = i; j < i + k && j < s.length(); j++) {
                sum += s[j] - '0';
            }

            ans += to_string(sum);
        }

        s = ans;
    }

    return s;
}

int main() {

    string s = "11111222223";
    int k = 3;

    cout << "Final Digit Sum: " << digitSum(s, k);
    return 0;
}
