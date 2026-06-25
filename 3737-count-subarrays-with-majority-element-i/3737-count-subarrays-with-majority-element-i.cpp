class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int count=0;

        for(int i=0;i<n;i++){
                int freq = 0;
                for(int j=i;j<n;j++){
                    if(nums[j]==target)
                        freq++;

                    int len = j-i+1;
                    if(freq*2>len)
                        count++;
                }
        }
        return count;
    }
};