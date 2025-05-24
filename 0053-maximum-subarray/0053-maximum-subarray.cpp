class Solution {
public:
    long long maxSubArray(vector<int>& nums) {
        long long maxi = LLONG_MIN,prefix=0;
        int n=nums.size();
        

        for(int i=0;i<n;i++){
            prefix+=nums[i];
            maxi=max(maxi,prefix);
            if(prefix<0){
                prefix=0;
            }
        }
        return maxi;
    }
};