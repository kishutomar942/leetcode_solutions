
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (abs(target - sum) < abs(target - closest)) {
                    closest = sum;
                }

                if (sum == target) {
                    return sum;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return closest;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    cout << "Closest Sum: "
         << obj.threeSumClosest(nums, target) << endl;

    return 0;
}
