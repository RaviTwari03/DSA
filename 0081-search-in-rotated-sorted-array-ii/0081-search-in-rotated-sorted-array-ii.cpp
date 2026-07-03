class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        //return binary_search(nums.begin(), nums.end(), target);
        int n = nums.size();
        int start = 0,end = n-1;

        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target){
                return true;
            }else if(nums[mid]>target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return false;
    }
};