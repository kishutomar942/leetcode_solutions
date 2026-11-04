#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost;
        multiset<int> low, high;

        long long sumLow = 0, sumHigh = 0;

        // Calculate cost for every window of size x
        for (int i = 0; i < n; i++) {

            if (low.empty() || nums[i] <= *low.rbegin()) {
                low.insert(nums[i]);
                sumLow += nums[i];
            }
            else {
                high.insert(nums[i]);
                sumHigh += nums[i];
            }

            // Remove outgoing element
            if (i >= x) {
                int val = nums[i - x];

                auto it = low.find(val);

                if (it != low.end()) {
                    low.erase(it);
                    sumLow -= val;
                }
                else {
                    high.erase(high.find(val));
                    sumHigh -= val;
                }
            }

            // Balance both sets
            if (low.size() < high.size()) {
                int val = *high.begin();

                high.erase(high.begin());
                low.insert(val);

                sumHigh -= val;
                sumLow += val;
            }
            else if (low.size() > high.size() + 1) {
                int val = *low.rbegin();

                low.erase(prev(low.end()));
                high.insert(val);

                sumLow -= val;
                sumHigh += val;
            }

            // Calculate window cost
            if (i >= x - 1) {
                long long median = *low.rbegin();

                long long operations =
                    median * (long long)low.size() - sumLow
                    + sumHigh - median * (long long)high.size();

                cost.push_back(operations);
            }
        }

        // Dynamic Programming
        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, INF)
        );

        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j <= k; j++) {

                if (dp[j][i] == INF)
                    continue;

                // Skip current position
                dp[j][i + 1] = min(
                    dp[j][i + 1],
                    dp[j][i]
                );

                // Select a window of size x
                if (j < k && i + x <= n) {
                    dp[j + 1][i + x] = min(
                        dp[j + 1][i + x],
                        dp[j][i] + cost[i]
                    );
                }
            }
        }

        return dp[k][n];
    }
};