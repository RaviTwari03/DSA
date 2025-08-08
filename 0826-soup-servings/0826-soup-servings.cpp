class Solution {
public:
    unordered_map<int, unordered_map<int, double>> dp;

    double solve(int a, int b) {
        // Base cases
        if (a <= 0 && b <= 0) return 0.5;  // Both empty at same time
        if (a <= 0) return 1.0;            // A is empty first
        if (b <= 0) return 0.0;            // B is empty first

        // Memoization check
        if (dp[a][b] > 0) return dp[a][b];

        // 4 possible serving combinations
        dp[a][b] = 0.25 * (
            solve(a - 100, b) +
            solve(a - 75, b - 25) +
            solve(a - 50, b - 50) +
            solve(a - 25, b - 75)
        );

        return dp[a][b];
    }

    double soupServings(int n) {
        // Optimization for large N
        if (n >= 5000) return 1.0;

        return solve(n, n);
    }
};
