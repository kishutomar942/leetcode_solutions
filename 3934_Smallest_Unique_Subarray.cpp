
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int smallestUniqueSubarray(vector<int>& nums) {
    int n = nums.size();

    vector<int> sa(n), rank(n), newRank(n);

    for (int i = 0; i < n; i++) {
        sa[i] = i;
        rank[i] = nums[i];
    }

    for (int k = 1; k < n; k *= 2) {
        sort(sa.begin(), sa.end(), [&](int a, int b) {
            if (rank[a] != rank[b])
                return rank[a] < rank[b];

            int x = (a + k < n) ? rank[a + k] : -1;
            int y = (b + k < n) ? rank[b + k] : -1;

            return x < y;
        });

        newRank[sa[0]] = 0;

        for (int i = 1; i < n; i++) {
            int a = sa[i - 1];
            int b = sa[i];

            int x = (a + k < n) ? rank[a + k] : -1;
            int y = (b + k < n) ? rank[b + k] : -1;

            newRank[b] = newRank[a] +
                (rank[a] != rank[b] || x != y);
        }

        rank = newRank;

        if (rank[sa[n - 1]] == n - 1)
            break;
    }

    vector<int> pos(n), lcp(n, 0);

    for (int i = 0; i < n; i++)
        pos[sa[i]] = i;

    int h = 0;

    for (int i = 0; i < n; i++) {
        int r = pos[i];

        if (r == 0)
            continue;

        int j = sa[r - 1];

        while (i + h < n && j + h < n &&
               nums[i + h] == nums[j + h])
            h++;

        lcp[r] = h;

        if (h > 0)
            h--;
    }

    int ans = n;

    for (int r = 0; r < n; r++) {
        int start = sa[r];

        int len = max(lcp[r],
                      (r + 1 < n ? lcp[r + 1] : 0)) + 1;

        if (len <= n - start)
            ans = min(ans, len);
    }

    return ans;
}

int main() {
    vector<int> nums = {3, 3, 3};

    cout << smallestUniqueSubarray(nums);

    return 0;
}
