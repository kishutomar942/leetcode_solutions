#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int minimumSumSubarray(vector<int>& nums, int l, int r) {
    int ans = INT_MAX;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n && j - i + 1 <= r; j++) {
            sum += nums[j];

            int len = j - i + 1;

            if (len >= l && len <= r && sum > 0) {
                ans = min(ans, sum);
            }
        }
    }

    return ans == INT_MAX ? -1 : ans;
}

int main() {
    vector<int> nums = {3, -2, 1, 4};
    int l = 2;
    int r = 3;

    cout << "Minimum Positive Sum: "
         << minimumSumSubarray(nums, l, r);

    return 0;
}