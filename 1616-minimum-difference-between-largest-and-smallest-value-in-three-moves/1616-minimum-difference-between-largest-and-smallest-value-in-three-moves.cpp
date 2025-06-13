class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;

        sort(nums.begin(), nums.end());

        int diff1 = nums[n - 4] - nums[0];     // Remove 3 largest
        int diff2 = nums[n - 3] - nums[1];     // Remove 2 largest, 1 smallest
        int diff3 = nums[n - 2] - nums[2];     // Remove 1 largest, 2 smallest
        int diff4 = nums[n - 1] - nums[3];     // Remove 3 smallest

        return min({diff1, diff2, diff3, diff4});
    }
};
