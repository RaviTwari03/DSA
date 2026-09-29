class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Odd length path can never have balanced parentheses
        if ((m + n - 1) % 2 == 1)
            return false;

        // Maximum possible balance
        int maxBal = m + n;

        vector<vector<vector<bool>>> dp(
            m,
            vector<vector<bool>>(n, vector<bool>(maxBal + 1, false))
        );

        // Start must be '('
        if (grid[0][0] != '(')
            return false;

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                int change = (grid[i][j] == '(') ? 1 : -1;

                for (int bal = 0; bal <= maxBal; bal++) {
                    int prev = bal - change;

                    if (prev < 0 || prev > maxBal)
                        continue;

                    bool possible = false;

                    // From top
                    if (i > 0 && dp[i - 1][j][prev])
                        possible = true;

                    // From left
                    if (j > 0 && dp[i][j - 1][prev])
                        possible = true;

                    dp[i][j][bal] = possible;
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};