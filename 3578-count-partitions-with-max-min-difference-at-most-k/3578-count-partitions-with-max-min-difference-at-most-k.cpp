class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1'000'000'007;
        int n = nums.size();
        vector<long long> dp(n+1, 0), pref(n+1, 0); 
        dp[0] = 1;
        pref[0] = 1;

        deque<int> dqMax, dqMin;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            while (!dqMax.empty() && nums[dqMax.back()] <= nums[r]) dqMax.pop_back();
            dqMax.push_back(r);
            while (!dqMin.empty() && nums[dqMin.back()] >= nums[r]) dqMin.pop_back();
            dqMin.push_back(r);

            while (!dqMax.empty() && !dqMin.empty() && (nums[dqMax.front()] - nums[dqMin.front()] > k)) {
                if (dqMax.front() == l) dqMax.pop_front();
                if (dqMin.front() == l) dqMin.pop_front();
                ++l;
            }

            long long sumSegmentStarts = pref[r] - (l-1 >= 0 ? pref[l-1] : 0);
            sumSegmentStarts %= MOD;
            if (sumSegmentStarts < 0) sumSegmentStarts += MOD;

            dp[r+1] = sumSegmentStarts;
            pref[r+1] = (pref[r] + dp[r+1]) % MOD;
        }

        return (int)dp[n];
    }
};