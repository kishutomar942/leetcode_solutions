
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int LOG = 20;

        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        // Next Greater Element
        vector<int> nxt(n + 1, n);
        vector<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] <= nums[i]) {
                st.pop_back();
            }

            if (!st.empty()) {
                nxt[i] = st.back();
            }

            st.push_back(i);
        }

        // Binary lifting
        vector<vector<int>> up(LOG, vector<int>(n + 1, n));
        vector<vector<long long>> sum(
            LOG, vector<long long>(n + 1, 0)
        );

        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];

            sum[0][i] =
                1LL * nums[i] * (nxt[i] - i - 1)
                - (pref[nxt[i]] - pref[i + 1]);
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i <= n; i++) {
                int mid = up[j - 1][i];

                up[j][i] = up[j - 1][mid];

                sum[j][i] =
                    sum[j - 1][i] + sum[j - 1][mid];
            }
        }

        // Calculate minimum operations
        auto getCost = [&](int l, int r) -> long long {
            long long res = 0;
            int p = l;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][p] <= r) {
                    res += sum[j][p];
                    p = up[j][p];
                }
            }

            res += 1LL * nums[p] * (r - p)
                 - (pref[r + 1] - pref[p + 1]);

            return res;
        };

        long long ans = 0;

        // Binary search
        for (int r = 0; r < n; r++) {
            int low = 0, high = r;

            while (low < high) {
                int mid = low + (high - low) / 2;

                if (getCost(mid, r) <= k) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }

            ans += r - low + 1;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n, k;

    cout << "Enter array size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    long long result = obj.countNonDecreasingSubarrays(nums, k);

    cout << "Number of valid subarrays: " << result << endl;

    return 0;
}
