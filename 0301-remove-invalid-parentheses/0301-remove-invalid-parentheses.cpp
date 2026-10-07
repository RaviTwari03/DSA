class Solution {
public:
    unordered_set<string> ans;

    void solve(string &s, int idx, int left, int right, int balance, string curr) {
        if (idx == s.size()) {
            if (left == 0 && right == 0 && balance == 0)
                ans.insert(curr);
            return;
        }

        char c = s[idx];

        if (c == '(') {
            if (left > 0)
                solve(s, idx + 1, left - 1, right, balance, curr);

            solve(s, idx + 1, left, right, balance + 1, curr + c);
        }

        else if (c == ')') {
            if (right > 0)
                solve(s, idx + 1, left, right - 1, balance, curr);

            if (balance > 0)
                solve(s, idx + 1, left, right, balance - 1, curr + c);
        }

        else {
            solve(s, idx + 1, left, right, balance, curr + c);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;

        for (char c : s) {
            if (c == '(') {
                left++;
            }
            else if (c == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }

        solve(s, 0, left, right, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};