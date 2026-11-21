
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent(n, -1);
        vector<int> last(26, -1);
        vector<int> previous(n, -1);

        // DFS on original tree
        vector<pair<int, int>> st;
        st.push_back({0, 0});

        while (!st.empty()) {
            auto [node, state] = st.back();
            st.pop_back();

            int c = s[node] - 'a';

            if (state == 0) {
                previous[node] = last[c];

                if (last[c] != -1) {
                    newParent[node] = last[c];
                } else {
                    newParent[node] = parent[node];
                }

                last[c] = node;

                st.push_back({node, 1});

                for (int i = adj[node].size() - 1; i >= 0; i--) {
                    st.push_back({adj[node][i], 0});
                }
            } else {
                last[c] = previous[node];
            }
        }

        // Build modified tree
        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        // Calculate subtree sizes
        vector<int> ans(n, 1);
        vector<int> order;
        st.clear();

        st.push_back({0, 0});

        while (!st.empty()) {
            int node = st.back().first;
            st.pop_back();

            order.push_back(node);

            for (int child : tree[node]) {
                st.push_back({child, 0});
            }
        }

        for (int i = n - 1; i > 0; i--) {
            int node = order[i];
            ans[newParent[node]] += ans[node];
        }

        return ans;
    }
};
