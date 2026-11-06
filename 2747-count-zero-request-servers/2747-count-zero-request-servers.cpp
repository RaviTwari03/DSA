class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        int m = queries.size();
        vector<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        unordered_map<int, int> cnt;
        vector<int> ans(m);

        int left = 0, right = 0;

        for (auto [t, idx] : q) {
            while (right < logs.size() && logs[right][1] <= t) {
                cnt[logs[right][0]]++;
                right++;
            }

            while (left < right && logs[left][1] < t - x) {
                cnt[logs[left][0]]--;

                if (cnt[logs[left][0]] == 0) {
                    cnt.erase(logs[left][0]);
                }

                left++;
            }

            ans[idx] = n - cnt.size();
        }

        return ans;
    }
};