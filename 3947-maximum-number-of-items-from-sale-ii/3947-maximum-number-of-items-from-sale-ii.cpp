class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, long long budget) {
        int n = items.size();
        int maxF = 0;
        long long minPrice = LLONG_MAX;

        for (const auto& it : items) {
            maxF = max(maxF, it[0]);
            minPrice = min(minPrice, (long long)it[1]);
        }

        vector<long long> freq(maxF + 1, 0);
        for (const auto& it : items) {
            freq[it[0]]++;
        }

        // multCount[d] = number of items with factor a multiple of d
        vector<long long> multCount(maxF + 1, 0);
        for (int d = 1; d <= maxF; ++d) {
            if (freq[d] == 0) continue;
            for (int m = d; m <= maxF; m += d) {
                multCount[d] += freq[m];
            }
        }

        // Group bonus-eligible copy counts by price (only when price < 2 * minPrice)
        map<long long, long long> priceToBonusCopies;
        for (const auto& it : items) {
            int f = it[0];
            long long price = it[1];
            long long eligible = multCount[f] - 1;
            if (eligible > 0 && price < 2 * minPrice) {
                priceToBonusCopies[price] += eligible;
            }
        }

        long long ans = 0;
        for (const auto& [price, avail] : priceToBonusCopies) {
            if (budget < price) break;
            long long take = min(avail, budget / price);
            ans += 2 * take;
            budget -= take * price;
        }

        ans += budget / minPrice;
        return ans;
    }
};