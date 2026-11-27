class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freeCount(n, 0);
        int minPrice = INT_MAX;

        // 1. Precompute free items gained on the first purchase of item i
        for (int i = 0; i < n; ++i) {
            minPrice = min(minPrice, items[i][1]);
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeCount[i]++;
                }
            }
        }

        // 2. 0/1 Knapsack for the first purchase of each item type
        // dp[b] = max items obtainable using exact/at most budget b (from first purchases)
        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; ++i) {
            int price = items[i][1];
            int gain = 1 + freeCount[i];
            for (int b = budget; b >= price; --b) {
                dp[b] = max(dp[b], dp[b - price] + gain);
            }
        }

        // 3. Spend any remaining budget on the cheapest item available
        int ans = 0;
        for (int b = 0; b <= budget; ++b) {
            int extraCopies = (budget - b) / minPrice;
            ans = max(ans, dp[b] + extraCopies);
        }

        return ans;
    }
};