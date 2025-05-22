class Solution {
public:
    bool rotateString(string str1, string str2) {
        if (str1.size() != str2.size()) return false;

        return (str1 + str1).find(str2) != string::npos;
    }
};