class Solution {
public:
    unordered_map<int, int> hmap;

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        int index = 0;

        for (int i = 0; i < n; i++) {
            hmap[nums[i]]++;

            if (i >= k - 1) {
                ans[index++] = getSum(x);

                int removeNum = nums[i - k + 1];
                hmap[removeNum]--;
                if (hmap[removeNum] == 0) hmap.erase(removeNum);
            }
        }

        return ans;
    }

    int getSum(int x) {
        int sum = 0;

        auto cmp = [&](int a, int b) {
            int f1 = hmap[a];
            int f2 = hmap[b];
            if (f1 == f2) return a < b; 
            return f1 < f2; 
        };

        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

        for (auto& [key, val] : hmap)
            pq.push(key);

        while (!pq.empty() && x-- > 0) {
            int top = pq.top();
            pq.pop();
            sum += top * hmap[top];
        }

        return sum;
    }
};
