class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> ans(m);

        // CHANGED:
        // last[j] stores the latest index in word1 where
        // word2[j] can be matched while still scanning from right.
        vector<int> last(m, -1);

        // CHANGED:
        // Build the latest possible positions for every suffix
        // of word2.
        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                --j;
            }
            --i;
        }

        // If the complete word2 cannot even be formed exactly,
        // one mismatch may still make it possible, so we don't
        // return here.
        
        bool mismatchUsed = false;
        j = 0;

        // CHANGED:
        // Greedily scan word1 from left to right.
        // The first feasible index is lexicographically smallest.
        for (i = 0; i < n && j < m; ++i) {

            // Exact match: always take it.
            if (word1[i] == word2[j]) {
                ans[j] = i;
                ++j;
            }

            // Mismatch can be used only once.
            //
            // We can safely use this mismatch if:
            // 1. We haven't used the mismatch yet.
            // 2. This is the last character of word2, OR
            // 3. The remaining suffix of word2 can be matched
            //    after the current index.
            else if (!mismatchUsed &&
                     (j == m - 1 || i < last[j + 1])) {

                ans[j] = i;
                ++j;
                mismatchUsed = true;
            }
        }

        // CHANGED:
        // Return the sequence only if all characters of word2
        // were successfully assigned.
        if (j == m)
            return ans;

        return {};
    }
};