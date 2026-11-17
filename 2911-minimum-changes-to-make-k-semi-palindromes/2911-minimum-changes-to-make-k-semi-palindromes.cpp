class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        // cost[i][j] = minimum changes to make s[i...j]
        // a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, 0));

        // Precompute all divisors
        vector<vector<int>> divisors(n + 1);

        for (int d = 1; d < n; d++) {
            for (int len = d * 2; len <= n; len += d) {
                divisors[len].push_back(d);
            }
        }

        // Calculate cost for every substring
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int len = j - i + 1;
                int best = n;

                for (int d : divisors[len]) {

                    int changes = 0;

                    for (int offset = 0; offset < d; offset++) {

                        int l = i + offset;
                        int r = j - d + 1 + offset;

                        while (l < r) {
                            if (s[l] != s[r])
                                changes++;

                            l += d;
                            r -= d;
                        }
                    }

                    best = min(best, changes);
                }

                cost[i][j] = best;
            }
        }

        // DP
        const int INF = 1e9;

        vector<vector<int>> dp(
            n + 1, vector<int>(k + 1, INF)
        );

        dp[0][0] = 0;

        // dp[i][j] = minimum changes to divide
        // first i characters into j semi-palindromes

        for (int i = 1; i <= n; i++) {
            for (int parts = 1; parts <= k; parts++) {

                for (int prev = 0; prev < i; prev++) {

                    if (i - prev < 2)
                        continue;

                    if (dp[prev][parts - 1] == INF)
                        continue;

                    dp[i][parts] = min(
                        dp[i][parts],
                        dp[prev][parts - 1] + cost[prev][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};