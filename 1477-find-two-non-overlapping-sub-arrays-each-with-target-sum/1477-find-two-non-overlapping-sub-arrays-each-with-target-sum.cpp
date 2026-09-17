class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> best(n + 1, INF);

        unordered_map<int, int> mp;
        mp[0] = 0;

        int prefix = 0;
        int ans = INF;

        for (int i = 1; i <= n; i++) {
            prefix += arr[i - 1];

            best[i] = best[i - 1];

            int need = prefix - target;

            if (mp.count(need)) {
                int j = mp[need];

                int len = i - j;

                if (best[j] != INF) {
                    ans = min(ans, best[j] + len);
                }

                best[i] = min(best[i], len);
            }

            mp[prefix] = i;
        }

        return ans == INF ? -1 : ans;
    }
};