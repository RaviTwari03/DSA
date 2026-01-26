class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> vals;
        vector<int> idx;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                vals.push_back(nums[i]);
                idx.push_back(i);
            }
        }

        int m = vals.size();
        if (m == 0) return nums;

        k %= m;  
        rotate(vals.begin(), vals.begin() + k, vals.end());

        for (int i = 0; i < m; i++) {
            nums[idx[i]] = vals[i];
        }

        return nums;
    }
};
