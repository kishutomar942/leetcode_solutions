
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    int n = nums.size();
    int i = 0;

    while (i < n) {
        int start = nums[i];

        while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
            i++;
        }

        int end = nums[i];

        if (start == end) {
            ans.push_back(to_string(start));
        }
        else {
            ans.push_back(to_string(start) + "->" + to_string(end));
        }

        i++;
    }

    return ans;
}

int main() {
    vector<int> nums = {0, 1, 2, 4, 5, 7};

    vector<string> result = summaryRanges(nums);

    for (string s : result) {
        cout << s << " ";
    }

    return 0;
}
