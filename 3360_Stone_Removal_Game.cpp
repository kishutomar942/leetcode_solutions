
#include <iostream>
using namespace std;

bool canAliceWin(int n) {
    int remove = 10;
    bool aliceTurn = true;

    while (n >= remove) {
        n -= remove;
        remove--;

        aliceTurn = !aliceTurn;
    }

    return !aliceTurn;
}

int main() {
    int n;

    cout << "Enter number of stones: ";
    cin >> n;

    if (canAliceWin(n)) {
        cout << "Alice Wins";
    } else {
        cout << "Bob Wins";
    }

    return 0;
}
