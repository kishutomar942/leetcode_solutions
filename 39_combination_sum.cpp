
#include <iostream>
#include <vector>
using namespace std;

void solve(int index, vector<int>& candidates, int target,
           vector<int>& current, vector<vector<int>>& ans) {

    if (target == 0) {
        ans.push_back(current);
        return;
    }

    if (index == candidates.size() || target < 0) {
        return;
    }

    // Include current element
    current.push_back(candidates[index]);

    solve(index, candidates, target - candidates[index],
          current, ans);

    // Backtracking
    current.pop_back();

    // Exclude current element
    solve(index + 1, candidates, target, current, ans);
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans;
    vector<int> current;

    solve(0, candidates, target, current, ans);

    cout << "Combination Sum: " << endl;

    for (auto combination : ans) {
        cout << "[ ";

        for (int num : combination) {
            cout << num << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}
