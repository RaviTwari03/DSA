class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;
        
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target)
                return mid;

            // Check if left part is sorted
            if (nums[st] <= nums[mid]) {
                // Check if target is in the left part
                if (nums[st] <= target && target < nums[mid])
                    end = mid - 1;
                else
                    st = mid + 1;
            }
            else { // Right part is sorted
                if (nums[mid] < target && target <= nums[end])
                    st = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return -1; // target not found
    }
};
