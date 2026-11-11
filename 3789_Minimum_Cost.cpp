#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int cost1, cost2, costBoth;
    int need1, need2;

    cin >> cost1 >> cost2 >> costBoth;
    cin >> need1 >> need2;

    long long both = min(need1, need2);

    long long ans =
        both * min(costBoth, cost1 + cost2);

    ans += max(0, need1 - need2) *
           min(cost1, costBoth);

    ans += max(0, need2 - need1) *
           min(cost2, costBoth);

    cout << ans << endl;

    return 0;
}