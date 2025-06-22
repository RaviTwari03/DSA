class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int n = s.length();
        
        // Process full groups
        for (int i = 0; i < n; i += k) {
            string group = s.substr(i, k);
            // If group is shorter than k, fill with 'fill'
            if (group.length() < k) {
                group.append(k - group.length(), fill);
            }
            result.push_back(group);
        }
        
        return result;
    }
};
