
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices) {

    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int i = 0; i < prices.size(); i++) {

        minPrice = min(minPrice, prices[i]);

        int profit = prices[i] - minPrice;

        maxProfit = max(maxProfit, profit);
    }

    return maxProfit;
}

int main() {

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Maximum Profit: "
         << maxProfit(prices);

    return 0;
}
