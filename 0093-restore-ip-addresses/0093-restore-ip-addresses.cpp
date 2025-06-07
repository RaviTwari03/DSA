class Solution {
public:
    void backtrack(string s, int start, int dots, string current, vector<string>& result) {
        if (dots == 4 && start == s.length()) {
            result.push_back(current.substr(0, current.length() - 1)); // remove trailing dot
            return;
        }

        if (dots > 4) return;

        for (int len = 1; len <= 3 && start + len <= s.length(); len++) {
            string part = s.substr(start, len);
            int val = stoi(part);

            if ((part[0] == '0' && part.length() > 1) || val > 255) continue;

            backtrack(s, start + len, dots + 1, current + part + ".", result);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if (s.length() < 4 || s.length() > 12) return result;

        backtrack(s, 0, 0, "", result);
        return result;
    }
};
