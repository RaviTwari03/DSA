class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=1;

        while(j<n){
            if(nums[i]!=nums[j]){
                nums[++i] = nums[j];
            }
            j++;
        }
        return i+1;
       
    }
};