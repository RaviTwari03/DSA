class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        int count = 0;
        int prefixSum = 0;
        prefixSumCount[0] = 1; // Base case for exact subarray sum == k

        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            // Check if there is a prefixSum that when removed results in k
            if(prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
                count += prefixSumCount[prefixSum - k];
            }

            // Update frequency of current prefixSum
            prefixSumCount[prefixSum]++;
        }

        return count;
    }
};
