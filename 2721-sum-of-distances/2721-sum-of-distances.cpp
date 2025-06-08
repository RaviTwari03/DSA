class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> indexMap;

        int n = nums.size();
        vector<long long> res(n, 0);

        // Store the indices of each number
        for (int i = 0; i < n; ++i) {
            indexMap[nums[i]].push_back(i);
        }

        // For each number, calculate prefix sums and distance
        for (auto& [num, indices] : indexMap) {
            int m = indices.size();
            vector<long long> prefix(m + 1, 0);
            
            for (int i = 0; i < m; ++i) {
                prefix[i + 1] = prefix[i] + indices[i];
            }

            for (int i = 0; i < m; ++i) {
                long long left = (long long)i * indices[i] - prefix[i];
                long long right = (prefix[m] - prefix[i + 1]) - (long long)(m - i - 1) * indices[i];
                res[indices[i]] = left + right;
            }
        }

        return res;
    }
};
