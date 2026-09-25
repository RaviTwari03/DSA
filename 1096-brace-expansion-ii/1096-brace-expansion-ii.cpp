class Solution {
public:
    string s;
    int pos;

    set<string> parseExpression() {
        set<string> res = parseConcat();

        while (pos < s.size() && s[pos] == ',') {
            pos++;
            set<string> right = parseConcat();
            res.insert(right.begin(), right.end());
        }

        return res;
    }

    set<string> parseConcat() {
        set<string> res = {""};

        while (pos < s.size() && s[pos] != '}' && s[pos] != ',') {
            set<string> cur;

            if (s[pos] == '{') {
                pos++;
                cur = parseExpression();
                pos++; // skip '}'
            } else {
                cur.insert(string(1, s[pos]));
                pos++;
            }

            set<string> next;

            for (string a : res) {
                for (string b : cur) {
                    next.insert(a + b);
                }
            }

            res = next;
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;

        set<string> res = parseExpression();

        return vector<string>(res.begin(), res.end());
    }
};