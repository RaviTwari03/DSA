#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> bracketPairs = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stk.push(ch);
            } else if (bracketPairs.count(ch)) {
                if (stk.empty() || stk.top() != bracketPairs[ch]) {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};
