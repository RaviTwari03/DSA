class Solution {
public:
    static const int MOD = 1e9 + 7;

    int countEffective(vector<int>& nums) {
        int n = nums.size();

        int OR_all = 0;
        for (int x : nums) OR_all |= x;

        vector<int> bits;
        for (int b = 0; b < 20; b++)
            if (OR_all & (1 << b))
                bits.push_back(b);

        int k = bits.size();
        int maxMask = 1 << k;

        vector<int> freq(maxMask, 0);

        for (int x : nums) {
            int m = 0;
            for (int j = 0; j < k; j++)
                if (x & (1 << bits[j]))
                    m |= (1 << j);
            freq[m]++;
        }

        vector<long long> pow2(n+1);
        pow2[0] = 1;
        for (int i = 1; i <= n; i++)
            pow2[i] = (pow2[i-1] * 2) % MOD;

        vector<int> g(maxMask);
        for (int m = 0; m < maxMask; m++)
            g[m] = freq[m];

        for (int b = 0; b < k; b++) {
            for (int m = 0; m < maxMask; m++) {
                if (m & (1 << b)) {
                    g[m] += g[m ^ (1 << b)];
                }
            }
        }

        long long ans = 0;
        for (int S = 1; S < maxMask; S++) {

            int complement = (maxMask - 1) ^ S;

            int noneHave = g[complement];

            int cntIntersect = n - noneHave;

            long long ways = pow2[n - cntIntersect];

            if (__builtin_popcount(S) & 1)
                ans = (ans + ways) % MOD;
            else
                ans = (ans - ways + MOD) % MOD;
        }

        return ans;
    }
};
