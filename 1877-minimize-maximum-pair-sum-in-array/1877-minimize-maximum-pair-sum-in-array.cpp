class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int maxResultv= 0;
        int i = 0, j=nums.size()-1;
        
        while(i<j){
            int sum = nums[i] + nums[j];
            maxResultv = max(maxResultv,sum);
            i++;
            j--;  
        }
        return maxResultv;

    }
};