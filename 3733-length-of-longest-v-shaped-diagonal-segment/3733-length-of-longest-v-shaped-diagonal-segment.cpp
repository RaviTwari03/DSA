#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n, m;
    vector<vector<int>> dir = {
        {1, 1}, {1, -1}, {-1, -1}, {-1, 1}
    };

public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // 4D DP array: dp[n][m][4][2]
        vector<vector<vector<vector<int>>>> dp(
            n, vector<vector<vector<int>>>(
                m, vector<vector<int>>(
                    4, vector<int>(2, -1))));

        int maxLength = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        maxLength = max(maxLength, 
                                        1 + dfs(grid, i, j, 2, d, true, dp));
                    }
                }
            }
        }

        return maxLength;
    }

private:
    bool isValid(vector<vector<int>>& grid, int i, int j, int expected) {
        return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == expected;
    }

    int dfs(vector<vector<int>>& grid, int i, int j, int expected, int d, bool canTurn, 
            vector<vector<vector<vector<int>>>>& dp) {

        int newI = i + dir[d][0];
        int newJ = j + dir[d][1];

        if (!isValid(grid, newI, newJ, expected)) {
            return 0;
        }

        int cIndex = canTurn ? 1 : 0;

        if (dp[newI][newJ][d][cIndex] != -1) {
            return dp[newI][newJ][d][cIndex];
        }

        int nextExpected = (expected == 2 ? 0 : 2);

        int maxLength = dfs(grid, newI, newJ, nextExpected, d, canTurn, dp);

        if (canTurn) {
            int newDir = (d + 1) % 4;
            maxLength = max(maxLength, dfs(grid, newI, newJ, nextExpected, newDir, false, dp));
        }

        dp[newI][newJ][d][cIndex] = 1 + maxLength;
        return dp[newI][newJ][d][cIndex];
    }
};
