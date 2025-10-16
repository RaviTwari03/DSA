class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> freq(value, 0);

        for (int num : nums) {
            int rem = ((num % value) + value) % value;
            freq[rem]++;
        }

        int mex = 0;
        while (true) {
            int rem = mex % value;
            if (freq[rem] == 0) break;  
            freq[rem]--;          
            mex++;
        }

        return mex;
    }
};