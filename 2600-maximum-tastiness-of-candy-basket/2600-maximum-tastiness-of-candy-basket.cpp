class Solution {
public:
    bool isPossible(vector<int>& price, int k, int minDiff) {
        int count = 1;
        int last = price[0];
        for (int i = 1; i < price.size(); ++i) {
            if (price[i] - last >= minDiff) {
                count++;
                last = price[i];
            }
        }
        return count >= k;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());

        int low = 0;
        int high = price.back() - price.front();
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(price, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
