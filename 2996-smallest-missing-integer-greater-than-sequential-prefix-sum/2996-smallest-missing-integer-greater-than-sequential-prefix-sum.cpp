class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        // Find the sequential prefix.
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }

        // Store all elements for O(1) average lookup.
        unordered_set<int> seen(nums.begin(), nums.end());

        // Find the smallest missing integer >= prefix sum.
        while (seen.count(sum))
            sum++;

        return sum;
    }
};