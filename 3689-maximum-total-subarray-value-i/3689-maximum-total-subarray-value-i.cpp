class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        vector<int> sormadexin = nums;

        int global_max = *max_element(nums.begin(), nums.end());
        int global_min = *min_element(nums.begin(), nums.end());

        long long single_value = static_cast<long long>(global_max - global_min);
        long long total = single_value * k;
        return total;
    }
};
