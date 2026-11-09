
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;

        while (left < right) {
            int width = right - left;

            int h = min(height[left], height[right]);

            int area = width * h;

            ans = max(ans, area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << "Maximum Water Area: "
         << obj.maxArea(height) << endl;

    return 0;
}
