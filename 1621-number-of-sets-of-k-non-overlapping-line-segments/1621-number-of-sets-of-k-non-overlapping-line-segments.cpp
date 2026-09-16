class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;

        long long ans = 1;
        int r = 2 * k;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n + k - i) % MOD;
            ans = ans * modInverse(i) % MOD;
        }

        return ans;
    }

    long long modInverse(long long x) {
        return power(x, 1e9 + 5);
    }

    long long power(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = res * a % 1000000007;

            a = a * a % 1000000007;
            b >>= 1;
        }

        return res;
    }
};