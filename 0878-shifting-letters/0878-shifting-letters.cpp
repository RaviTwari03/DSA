class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        vector<long long> suffixShifts(n);
        long long totalShift = 0;

        for (int i = n - 1; i >= 0; --i) {
            totalShift = (totalShift + shifts[i]) % 26;
            suffixShifts[i] = totalShift;
        }

        for (int i = 0; i < n; ++i) {
            int originalChar = s[i] - 'a';
            int newChar = (originalChar + suffixShifts[i]) % 26;
            s[i] = 'a' + newChar;
        }

        return s;
    }
};
