#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        int m = logs.size();
        int q = queries.size();

        sort(logs.begin(), logs.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < q; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        unordered_map<int, int> mp;
        vector<int> ans(q);

        int left = 0, right = 0;
        int active = 0;

        for (auto [time, index] : sortedQueries) {

            while (right < m && logs[right][1] <= time) {
                int id = logs[right][0];
                mp[id]++;

                if (mp[id] == 1)
                    active++;

                right++;
            }

            while (left < right && logs[left][1] < time - x) {
                int id = logs[left][0];
                mp[id]--;

                if (mp[id] == 0)
                    active--;

                left++;
            }

            ans[index] = n - active;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n = 3;
    vector<vector<int>> logs = {
        {1, 3},
        {2, 6},
        {1, 5}
    };

    int x = 5;

    vector<int> queries = {10, 11};

    vector<int> result = obj.countServers(n, logs, x, queries);

    cout << "Output: ";

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}