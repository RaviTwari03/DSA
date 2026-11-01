class Solution {
public:
    string getHappyString(int n, int k) {
        if (k > 3 * (1 << (n - 1))) {
            return "";
        }

        string ans = "";

        for (int i = 0; i < n; i++) {
            int remaining = 1 << (n - i - 1);

            for (char c = 'a'; c <= 'c'; c++) {
                if (!ans.empty() && ans.back() == c) {
                    continue;
                }

                if (k <= remaining) {
                    ans += c;
                    break;
                }

                k -= remaining;
            }
        }

        return ans;
    }
};
