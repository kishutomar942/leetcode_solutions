
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int numOfStrings(vector<string>& patterns, string word) {
    int count = 0;

    for (int i = 0; i < patterns.size(); i++) {
        if (word.find(patterns[i]) != string::npos) {
            count++;
        }
    }

    return count;
}

int main() {
    vector<string> patterns = {"a", "abc", "bc", "d"};
    string word = "abc";

    cout << numOfStrings(patterns, word);

    return 0;
}
