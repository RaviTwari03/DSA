class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }

private:
    string build(string str) {
        stack<char> st;
        for (char ch : str) {
            if (ch != '#') {
                st.push(ch);
            } else if (!st.empty()) {
                st.pop();
            }
        }

        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
