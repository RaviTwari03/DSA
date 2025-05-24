class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        // Two possibilities:
        // 1. Product of three largest numbers
        // 2. Product of two smallest (possibly negative) and the largest number
        return max(nums[n-1] * nums[n-2] * nums[n-3],
                   nums[0] * nums[1] * nums[n-1]);
    }
};
