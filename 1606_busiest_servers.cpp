#include <bits/stdc++.h>
using namespace std;

vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

    set<int> available;

    for (int i = 0; i < k; i++) {
        available.insert(i);
    }

    priority_queue<pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>> busy;

    vector<int> count(k, 0);

    for (int i = 0; i < arrival.size(); i++) {

        while (!busy.empty() && busy.top().first <= arrival[i]) {
            available.insert(busy.top().second);
            busy.pop();
        }

        if (available.empty()) {
            continue;
        }

        int server = i % k;

        auto it = available.lower_bound(server);

        if (it == available.end()) {
            it = available.begin();
        }

        int selected = *it;

        available.erase(it);

        count[selected]++;

        busy.push({arrival[i] + load[i], selected});
    }

    int maxi = *max_element(count.begin(), count.end());

    vector<int> ans;

    for (int i = 0; i < k; i++) {
        if (count[i] == maxi) {
            ans.push_back(i);
        }
    }

    return ans;
}

int main() {

    int k = 3;

    vector<int> arrival = {1, 2, 3, 4, 5};
    vector<int> load = {5, 2, 3, 3, 3};

    vector<int> ans = busiestServers(k, arrival, load);

    cout << "Busiest Servers: ";

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}