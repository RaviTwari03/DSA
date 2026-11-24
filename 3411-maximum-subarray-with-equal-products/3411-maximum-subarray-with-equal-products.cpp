class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            long long prod = 1, g = 0, l = 1;

            for (int j = i; j < n; j++) {
                int x = nums[j];

                g = gcd(g, (long long)x);
                l = l / gcd(l, (long long)x) * x;

                if (prod > 1e18 / x)
                    break;

                prod *= x;

                if (prod == g * l)
                    ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};