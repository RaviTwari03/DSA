class Solution {
public:
    void backtrack(vector<int>& nums, vector<bool>& visited, vector<int>& temp, vector<vector<int>>& ans) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;

            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            visited[i] = true;
            temp.push_back(nums[i]);

            backtrack(nums, visited, temp, ans);

            visited[i] = false;
            temp.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // important step
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        backtrack(nums, visited, temp, ans);
        return ans;
    }
};
