
class Solution {
public:
    const int MOD = 1e9 + 7;
    int countCoprime(vector<vector<int>>& mat) {
        int row = mat.size();
        unordered_map<int, int> dp, next;

        for(int v : mat[0]) dp[v] = (dp[v] + 1) % MOD;

        for(int i = 1; i < row; ++i){
            next.clear();

            for(auto [g, cnt] : dp){
                for(int v : mat[i]){
                    int curr_gcd = __gcd(g, v);
                    next[curr_gcd] = (next[curr_gcd] + cnt) % MOD;
                }
            }

            dp.swap(next);
        }
        return dp[1] % MOD;
    }
};