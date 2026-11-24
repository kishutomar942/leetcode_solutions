
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int maxLength(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        __int128 product = 1;
        long long g = 0, l = 1;

        for (int j = i; j < n; j++) {
            product *= nums[j];

            g = gcd(g, (long long)nums[j]);
            l = l / gcd(l, (long long)nums[j]) * nums[j];

            if (product == (__int128)g * l) {
                ans = max(ans, j - i + 1);
            }

            if (product > (__int128)g * l) {
                break;
            }
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {2, 6};

    cout << maxLength(nums);

    return 0;
}
