class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
       int n = nums.size();
        sort(nums.begin(),nums.end(),[](int a,int b){
            return abs(a)>abs(b);
        });

        int k = (n+1)/2;
        long long ans  = 0;

        for(int i=0; i<n;i++){
            long long sq = 1LL*nums[i]*nums[i];
            if(i<k)
                ans+=sq;
            else
                ans-=sq;
        }
        return ans;
    }
};