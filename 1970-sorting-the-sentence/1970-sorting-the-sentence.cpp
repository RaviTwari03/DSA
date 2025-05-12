class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(10); // assuming max 9 words (index 1-9)
        string word;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                int pos = word.back() - '0';
                word.pop_back(); // remove the digit
                words[pos] = word;
                word = "";
            } else {
                word += s[i];
            }
        }

        // Add the last word
        if (!word.empty()) {
            int pos = word.back() - '0';
            word.pop_back();
            words[pos] = word;
        }

        string result;
        for (int i = 1; i < 10; ++i) {
            if (!words[i].empty()) {
                if (!result.empty()) result += " ";
                result += words[i];
            }
        }

        return result;
    }
};
