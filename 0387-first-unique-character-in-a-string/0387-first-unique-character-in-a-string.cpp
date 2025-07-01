class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);

        // First pass: count frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Second pass: find the first unique character
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1; // No unique character
    }
};
