
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        return min({
            nums[n - 1] - nums[2],
            nums[n - 2] - nums[1],
            nums[n - 3] - nums[0]
        });
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 4, 7, 8, 10};

    cout << obj.minimizeSum(nums);

    return 0;
}
