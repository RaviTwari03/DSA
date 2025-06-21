class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freqMap;
        for (char ch : word) {
            freqMap[ch]++;
        }

        vector<int> freqs;
        for (auto [ch, freq] : freqMap) {
            freqs.push_back(freq);
        }

        sort(freqs.begin(), freqs.end());

        int n = freqs.size();
        int result = INT_MAX;

        for (int i = 0; i < n; i++) {
            int deletions = 0;
            int target = freqs[i];

            for (int j = i + 1; j < n; j++) {
                if (freqs[j] > target + k) {
                    deletions += freqs[j] - (target + k);
                }
            }

            for (int j = 0; j < i; j++) {
                deletions += freqs[j];
            }

            result = min(result, deletions);
        }

        return result;
    }
};
