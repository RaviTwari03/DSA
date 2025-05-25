class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        for(int start = 0; start < n; ++start) {
            int sum = 0;
            for(int end = start; end < n; ++end) {
                sum += nums[end];
                if(sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};
