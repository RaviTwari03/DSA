class Solution {
public:
    // bool solve(string &s, int l, int r){
    //     while(l<=r){
    //         if(s[l]!=s[r]){
    //             return false;
    //         }l++;
    //         r--;
    //     }
    //     return true;
    // }
    // string longestPalindrome(string s) {
    //     int max_length = INT_MIN;
    //     int startPoint=0;
    //     int n = s.length();

    //     for(int i=0;i<n;i++){
    //         for (int j=i;j<n;j++){
    //             if(solve(s,i,j)){
    //                 if(j-i+1>max_length){
    //                     max_length=j-i+1;
    //                     startPoint=i;
    //                 }
    //             }
    //         }
    //     }
    //     return s.substr(startPoint,max_length);
    // }
   
    string s;
    vector<vector<int>> dp; 

    bool solve(int l, int r) {
        if (l >= r) return true; 

        if (dp[l][r] != -1) return dp[l][r]; 

        if (s[l] == s[r]) {
            dp[l][r] = solve(l + 1, r - 1);
        } else {
            dp[l][r] = 0;
        }
        return dp[l][r];
    }

    string longestPalindrome(string str) {
        s = str;
        int n = s.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));

        int maxLength = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(i, j)) {
                    if (j - i + 1 > maxLength) {
                        maxLength = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLength);
    }


};