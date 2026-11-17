
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int len = 2; len <= n; len++) {
            for (int d = 1; d < len; d++) {
                if (len % d != 0) continue;

                for (int l = 0; l + len <= n; l++) {
                    int changes = 0;
                    int r = l + len - 1;

                    for (int rem = 0; rem < d; rem++) {
                        int left = l + rem;
                        int right = r - ((len - 1 - rem) % d);

                        while (left < right) {
                            if (s[left] != s[right])
                                changes++;

                            left += d;
                            right -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        vector<vector<int>> dp(
            n + 1, vector<int>(k + 1, INF)
        );

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int p = 0; p <= i - 2; p++) {
                    if (dp[p][j - 1] == INF)
                        continue;

                    dp[i][j] = min(
                        dp[i][j],
                        dp[p][j - 1] + cost[p][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};

int main() {
    Solution obj;

    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    cout << "Minimum changes: "
         << obj.minimumChanges(s, k) << endl;

    return 0;
}
