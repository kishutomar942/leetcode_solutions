
#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;

    for (int i = 0; i < nums.size(); i++) {
        ans = ans ^ nums[i];
    }

    return ans;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};

    cout << "Single Number: " << singleNumber(nums);

    return 0;
}
