class Solution {
public:

    using ll = long long;
    
    struct Node{ 
        ll ways, wav;
    };

    string s;
    Node dp[20][2][2][11][11];
    bool vis[20][2][2][11][11];

    Node solveDP(int pos, int tight, int started, int prev, int prev2){
        if(pos==s.size()){
            return{1,0};
        }

        if(vis[pos][tight][started][prev+1][prev2+1])
            return dp[pos][tight][started][prev+1][prev2+1];

        vis[pos][tight][started][prev+1][prev2+1] = true;

        int limit = tight?s[pos] - '0' : 9;
        Node ans = {0,0};

        for(int d = 0; d<=limit; d++){
            int ntight = (tight && d==limit);
            int nstarted = (started || d!=0);
            int nprev2 = prev2, nprev = prev;

            if(nstarted){
                nprev2 = prev;
                nprev=d;
            }

            Node nxt = solveDP(pos+1,ntight,nstarted,nprev,nprev2);
            ll addWays = nxt.ways;
            ll addWav = nxt.wav;

            if(started&&prev2!=-1){
                if(prev>prev2 && prev>d) addWav += addWays;
                else if(prev<prev2 && prev<d) addWav+=addWays;
            }

            ans.ways += addWays;
            ans.wav += addWav;
        }

        dp[pos][tight][started][prev+1][prev2+1] = ans;
        return ans;
    }

    ll calc(ll x){
        if(x<100) return 0;
        s = to_string(x);

        memset(vis,0,sizeof(vis));
        Node res = solveDP(0,1,0,-1,-1);
        return res.wav;
    }

        
    
    long long totalWaviness(long long num1, long long num2) {
       return calc(num2) - calc(num1-1);

        
    }
};