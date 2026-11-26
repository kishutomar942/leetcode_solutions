
#include <bits/stdc++.h>
using namespace std;

int maximumSafenessFactor(vector<vector<int>>& grid) {
    int n = grid.size();

    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < n &&
                dist[nx][ny] == -1) {

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    priority_queue<tuple<int, int, int>> pq;

    vector<vector<int>> best(n, vector<int>(n, -1));

    best[0][0] = dist[0][0];
    pq.push({best[0][0], 0, 0});

    while (!pq.empty()) {
        auto [safe, x, y] = pq.top();
        pq.pop();

        if (x == n - 1 && y == n - 1)
            return safe;

        if (safe < best[x][y])
            continue;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < n) {

                int newSafe = min(safe, dist[nx][ny]);

                if (newSafe > best[nx][ny]) {
                    best[nx][ny] = newSafe;
                    pq.push({newSafe, nx, ny});
                }
            }
        }
    }

    return 0;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 1},
        {0, 0, 0},
        {0, 0, 0}
    };

    cout << "Maximum Safeness Factor: "
         << maximumSafenessFactor(grid);

    return 0;
}

