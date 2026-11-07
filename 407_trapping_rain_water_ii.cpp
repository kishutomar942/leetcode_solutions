
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        if (m < 3 || n < 3)
            return 0;

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<bool>> visited(
            m, vector<bool>(n, false)
        );

        // Add boundary cells
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});

            visited[i][0] = true;
            visited[i][n - 1] = true;
        }

        for (int j = 1; j < n - 1; j++) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m - 1][j], m - 1, j});

            visited[0][j] = true;
            visited[m - 1][j] = true;
        }

        int water = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();

            int h = cell[0];
            int x = cell[1];
            int y = cell[2];

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 ||
                    nx >= m || ny >= n ||
                    visited[nx][ny]) {
                    continue;
                }

                visited[nx][ny] = true;

                if (heightMap[nx][ny] < h) {
                    water += h - heightMap[nx][ny];
                }

                pq.push({
                    max(h, heightMap[nx][ny]),
                    nx,
                    ny
                });
            }
        }

        return water;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> heightMap = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}
    };

    cout << "Trapped Rain Water: "
         << obj.trapRainWater(heightMap);

    return 0;
}

