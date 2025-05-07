class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> dist(n, vector<int>(m, -1));
        dist[0][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!pq.empty()) {
            auto [d, x, y] = pq.top();
            pq.pop();

            if (d > dist[x][y]) continue;

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int waitTime = max(0, moveTime[nx][ny] - d);
                    int newDist = d + waitTime + 1;

                    if (dist[nx][ny] == -1 || newDist < dist[nx][ny]) {
                        dist[nx][ny] = newDist;
                        pq.push({newDist, nx, ny});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};
