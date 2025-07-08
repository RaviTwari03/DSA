class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0]; // sort by start day
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), cmp);

        // Extract start days for binary search
        vector<int> startDays(n);
        for (int i = 0; i < n; ++i)
            startDays[i] = events[i][0];

        // dp[i][j] → max value using first i events and attending j events
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; --i) {
            int nextIndex = upper_bound(startDays.begin(), startDays.end(), events[i][1]) - startDays.begin();

            for (int j = 1; j <= k; ++j) {
                // Max of: skip or take
                dp[i][j] = max(dp[i + 1][j], events[i][2] + dp[nextIndex][j - 1]);
            }
        }

        return dp[0][k];
    }
};
