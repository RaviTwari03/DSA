class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }

        int length = 0;
        bool centerUsed = false;

        for (auto& [word, count] : freq) {
            string rev = string{word.rbegin(), word.rend()};

            if (word == rev) {
                int pairs = count / 2;
                length += pairs * 4;
                freq[word] -= pairs * 2;

                if (!centerUsed && freq[word] > 0) {
                    length += 2;
                    centerUsed = true;
                }
            } else if (freq.count(rev)) {
                int pairCount = min(freq[word], freq[rev]);
                length += pairCount * 4;
                freq[word] -= pairCount;
                freq[rev] -= pairCount;
            }
        }

        return length;
    }
};
