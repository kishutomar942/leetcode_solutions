
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maximumSaleItems(vector<vector<int>>& items, int budget) {
    int n = items.size();

    vector<int> dp(budget + 1, 0);

    int minPrice = INT_MAX;

    // Find minimum price
    for (auto &item : items) {
        minPrice = min(minPrice, item[1]);
    }

    // Process each item
    for (int i = 0; i < n; i++) {

        int factor = items[i][0];
        int price = items[i][1];

        int freeItems = 0;

        // Count free items
        for (int j = 0; j < n; j++) {
            if (i != j && items[j][0] % factor == 0) {
                freeItems++;
            }
        }

        // 0/1 Knapsack
        for (int j = budget; j >= price; j--) {
            dp[j] = max(dp[j],
                        dp[j - price] + freeItems + 1);
        }
    }

    int ans = 0;

    // Use remaining budget
    for (int i = 0; i <= budget; i++) {
        ans = max(ans, dp[i] + (budget - i) / minPrice);
    }

    return ans;
}

int main() {
    int n, budget;

    cout << "Enter number of items: ";
    cin >> n;

    vector<vector<int>> items(n, vector<int>(2));

    cout << "Enter factor and price of each item:\n";

    for (int i = 0; i < n; i++) {
        cin >> items[i][0] >> items[i][1];
    }

    cout << "Enter budget: ";
    cin >> budget;

    cout << "Maximum number of items: "
         << maximumSaleItems(items, budget) << endl;

    return 0;
}
