class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // deque<int> dq; 
        // vector<int> result;

        // for (int i = 0; i < nums.size(); ++i) {
        //     if (!dq.empty() && dq.front() <= i - k) {
        //         dq.pop_front();
        //     }

        //     while (!dq.empty() && nums[dq.back()] < nums[i]) {
        //         dq.pop_back();
        //     }

           
        //     dq.push_back(i);

        //     if (i >= k - 1) {
        //         result.push_back(nums[dq.front()]);
        //     }
        // }

        // return result;
       
    // vector<int> ans;
    // int n = nums.size();
    
    // for (int i = 0; i <= n - k; i++) {   // i goes from 0 to n-k
    //     int total = INT_MIN;
    //     for (int j = i; j < i + k; j++) { // j runs from i to i+k-1
    //         total = max(total, nums[j]);
    //     }
    //     ans.push_back(total);
    // }

    // return ans;

     deque<int> d;
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (!d.empty() && d.front() <= i - k) {
                d.pop_front();
            }

            while (!d.empty() && nums[i] > nums[d.back()]) {
                d.pop_back();
            }

            d.push_back(i);

            if (i >= k - 1) {
                ans.push_back(nums[d.front()]);
            }
        }

        return ans;
    }
};
