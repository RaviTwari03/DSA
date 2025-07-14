class Solution {
public:
        int fibon(int n, vector<int>&dp){
            if(n<=1) return n;

            if(dp[n]!=-1) 
                return dp[n];

            return dp[n] = (fibon(n-1,dp)+fibon((n-2),dp));
        }


    int fib(int n) {
        // if(n<=1) return n;
        // return (fib(n-1)+fib(n-2));
        vector<int>dp(n+
        1,-1);
        return fibon(n,dp);
    }
};