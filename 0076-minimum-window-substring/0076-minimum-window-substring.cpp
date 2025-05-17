class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> targetFreq;
        for (char c : t) {
            targetFreq[c]++;
        }

        int required = targetFreq.size();
        unordered_map<char, int> windowFreq;

        int left = 0, right = 0;
        int formed = 0;

        int minLen = INT_MAX;
        int minLeft = 0;

        while (right < s.size()) {
            char c = s[right];
            windowFreq[c]++;

            if (targetFreq.count(c) && windowFreq[c] == targetFreq[c]) {
                formed++;
            }

            // Try to shrink the window from the left
            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                char leftChar = s[left];
                windowFreq[leftChar]--;
                if (targetFreq.count(leftChar) && windowFreq[leftChar] < targetFreq[leftChar]) {
                    formed--;
                }
                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};
