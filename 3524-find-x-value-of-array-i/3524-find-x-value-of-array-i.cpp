class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> dp(k, 0);
        vector<long long> ans(k, 0);

        for (int num : nums) {
            vector<long long> next(k, 0);

            int x = num % k;

            next[x]++;

            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int nr = (r * x) % k;
                    next[nr] += dp[r];
                }
            }

            for (int r = 0; r < k; r++) {
                ans[r] += next[r];
            }

            dp = next;
        }

        return ans;
    }
};