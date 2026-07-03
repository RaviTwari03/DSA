class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        // Sieve
        vector<bool> prime(mx + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= mx; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= mx; j += i)
                    prime[j] = false;
            }
        }

        // prime -> divisible indices
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            for (int p = 2; p * p <= x; p++) {
                if (x % p == 0) {
                    if (prime[p])
                        mp[p].push_back(i);

                    while (x % p == 0)
                        x /= p;
                }
            }

            if (x > 1 && prime[x])
                mp[x].push_back(i);
        }

        vector<int> dist(n, -1);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        unordered_set<int> usedPrime;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1)
                return dist[i];

            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = dist[i] + 1;
                q.push(i + 1);
            }

            int val = nums[i];

            if (prime[val] && !usedPrime.count(val)) {
                usedPrime.insert(val);

                for (int idx : mp[val]) {
                    if (dist[idx] == -1) {
                        dist[idx] = dist[i] + 1;
                        q.push(idx);
                    }
                }
            }
        }

        return -1;
    }
};