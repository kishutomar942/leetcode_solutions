
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int climbStairs(int n, vector<int>& costs) {

    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= 3; j++) {

            if (i - j >= 0) {

                int cost = costs[i - 1] + j * j;

                dp[i] = min(dp[i],
                            dp[i - j] + cost);
            }
        }
    }

    return dp[n];
}

int main() {

    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    vector<int> costs(n);

    cout << "Enter stair costs: ";

    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    cout << "Minimum Cost: "
         << climbStairs(n, costs) << endl;

    return 0;
}
