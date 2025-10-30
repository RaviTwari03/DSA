class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        if (m == 0) return {};
        int n = isWater[0].size();

        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int,int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }

        const int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            int curH = ans[i][j];
            for (auto &d : dirs) {
                int ni = i + d[0];
                int nj = j + d[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && ans[ni][nj] == -1) {
                    ans[ni][nj] = curH + 1;
                    q.emplace(ni, nj);
                }
            }
        }

        return ans;
    }
};
