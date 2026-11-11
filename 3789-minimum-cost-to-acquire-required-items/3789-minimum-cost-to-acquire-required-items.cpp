class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
    //     // if(costBoth>=cost1+cost2){
    //     //     return 1LL * need1 * cost1 + 1LL *need2 * cost2;
    //     // }

    //     // long long both = min(need1, need2);
    //     // long long cost = both * costBoth;

    //     // need1 -= both;
    //     // need2 -= both;

    //     // cost += 1LL * need1 * cost1;
    //     // cost += 1LL * need2 * cost2;

    //     // return cost;

    //     if(costBoth >= cost1 + cost2){
    //         return 1LL * need1 * cost1 + 1LL * need2 * cost2;
    //     }
        
    //     if(costBoth <= min(cost1 , cost2)){
    //         return 1LL * max(need1,need2) * costBoth;
    //     }
    //     // long long ans = LLONG_MAX;

    //     // {
    //     //     long long both = min(need1, need2);
    //     //     long long cost = both * costBoth;
    //     //     cost += 1LL * (need1 -both) * cost1;
    //     //     cost += 1LL * (need2 -both) * cost2;
    //     //     ans = min(ans,cost);
    //     // }
    //     // {
    //     //     long long both = max(need1, need2);
    //     //     long long cost = cost * costBoth;
    //     //     ans = min(ans,cost);
    //     // }
    //     // return ans;
    //     long long both = min(need1, need2);
    //     return both * costBoth +1LL * (need1 - both) * cost1 + 1LL * (need2 - both) * cost2;
    // 

        auto calc = [&](long long x){
            return x * costBoth + max(0LL,(long long)need1-x)*cost1 + max(0LL,(long long)need2-x)*cost2;
        };
        long long ans = LLONG_MAX;

        long long a = min(need1, need2);
        long long b = max(need1, need2);

        ans = min(ans,calc(0));
        ans = min(ans,calc(a));
        ans = min(ans,calc(need1));
        ans = min(ans,calc(need2));
        ans = min(ans,calc(b));

        return ans;
    }
};