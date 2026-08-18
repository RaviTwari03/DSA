class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == n)
            return *max_element(nums.begin(), nums.end());

        unordered_map<int, int> cnt;
        for (int x : nums) cnt[x]++;

        if (k == 1) {
            int ans = -1;
            for (int x : nums) {
                if (cnt[x] == 1)
                    ans = max(ans, x);
            }
            return ans;
        }

        int ans = -1;
        if (cnt[nums.front()] == 1)
            ans = max(ans, nums.front());
        if (cnt[nums.back()] == 1)
            ans = max(ans, nums.back());

        return ans;
    }
};