class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int count = 0;
        int pref = 0;

        for (int i = 0; i < n; i++) {
            pref += nums[i];
            if (nums[i] == 0) {
                if (pref == sum - pref)
                    count += 2;
                else if (pref + 1 == sum - pref || pref - 1 == sum - pref)
                    count++;
            }
        }
        return count;
    }
};