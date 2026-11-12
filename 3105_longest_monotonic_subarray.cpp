#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestMonotonicSubarray(vector<int>& nums) {

    int inc = 1;
    int dec = 1;
    int ans = 1;

    for (int i = 1; i < nums.size(); i++) {

        if (nums[i] > nums[i - 1]) {
            inc++;
            dec = 1;
        }
        else if (nums[i] < nums[i - 1]) {
            dec++;
            inc = 1;
        }
        else {
            inc = 1;
            dec = 1;
        }

        ans = max(ans, max(inc, dec));
    }

    return ans;
}

int main() {

    vector<int> nums = {1, 4, 3, 3, 2};

    cout << "Longest Monotonic Subarray: "
         << longestMonotonicSubarray(nums);

    return 0;
}