
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minMoves(vector<int>& nums) {
    int maxi = *max_element(nums.begin(), nums.end());

    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
        count += maxi - nums[i];
    }

    return count;
}

int main() {
    vector<int> nums = {2, 1, 3};

    cout << "Minimum moves: " << minMoves(nums);

    return 0;
}
