class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        // Remove consecutive duplicates
        vector<int> clean;
        clean.push_back(nums[0]);
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1]) {
                clean.push_back(nums[i]);
            }
        }

        // Count hills and valleys
        for (int i = 1; i < clean.size() - 1; ++i) {
            if ((clean[i] > clean[i - 1] && clean[i] > clean[i + 1]) ||
                (clean[i] < clean[i - 1] && clean[i] < clean[i + 1])) {
                count++;
            }
        }

        return count;
    }
};
