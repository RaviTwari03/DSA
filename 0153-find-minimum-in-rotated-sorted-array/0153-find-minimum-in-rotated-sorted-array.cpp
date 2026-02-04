class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int start = 0 ;
        int end = nums.size()-1;

        while(start<=end){
            int mid = start + (end-start)/2;

            
        }
        return nums[0];
    }
};