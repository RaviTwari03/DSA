class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Apply doubling operation
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        // Step 2: Move non-zero elements to the front
        vector<int> result;
        for (int num : nums) {
            if (num != 0) {
                result.push_back(num);
            }
        }

        // Step 3: Add trailing zeros
        while (result.size() < n) {
            result.push_back(0);
        }

        return result;
    }
};
