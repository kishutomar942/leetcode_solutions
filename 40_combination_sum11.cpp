
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int>& candidates, int target,
           int index, vector<int>& current,
           vector<vector<int>>& ans) {

    if (target == 0) {
        ans.push_back(current);
        return;
    }

    for (int i = index; i < candidates.size(); i++) {

        // Skip duplicate elements
        if (i > index && candidates[i] == candidates[i - 1])
            continue;

        if (candidates[i] > target)
            break;

        current.push_back(candidates[i]);

        solve(candidates, target - candidates[i],
              i + 1, current, ans);

        current.pop_back();
    }
}

int main() {

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    vector<int> current;

    solve(candidates, target, 0, current, ans);

    cout << "Unique combinations are:\n";

    for (auto combination : ans) {
        for (int x : combination)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}

