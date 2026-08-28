class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int half = n / 2;

        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        vector<int> rem = halfCnt;
        bool possible = true;

        for (int i = 0; i < half; i++) {
            int c = target[i] - 'a';

            if (rem[c] == 0) {
                possible = false;
                break;
            }

            rem[c]--;
        }

        if (possible) {
            string left = target.substr(0, half);

            string ans = left;

            if (n % 2)
                ans += mid;

            string right = left;
            reverse(right.begin(), right.end());

            ans += right;

            if (ans > target)
                return ans;
        }

        for (int pos = half - 1; pos >= 0; pos--) {

            rem = halfCnt;

            bool ok = true;

            for (int i = 0; i < pos; i++) {
                int c = target[i] - 'a';

                if (rem[c] == 0) {
                    ok = false;
                    break;
                }

                rem[c]--;
            }

            if (!ok)
                continue;

            int targetChar = target[pos] - 'a';

            for (int c = targetChar + 1; c < 26; c++) {

                if (rem[c] == 0)
                    continue;

                string left = target.substr(0, pos);

                left += char('a' + c);

                rem[c]--;

                for (int j = 0; j < 26; j++) {
                    while (rem[j] > 0) {
                        left += char('a' + j);
                        rem[j]--;
                    }
                }

                string right = left;
                reverse(right.begin(), right.end());

                string ans = left;

                if (n % 2)
                    ans += mid;

                ans += right;

                return ans;
            }
        }

        return "";
    }
};