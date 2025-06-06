class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, int start) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);                  // Choose
            backtrack(nums, result, start + 1);          // Explore
            swap(nums[start], nums[i]);                  // Unchoose (backtrack)
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, result, 0);
        return result;
    }
};

