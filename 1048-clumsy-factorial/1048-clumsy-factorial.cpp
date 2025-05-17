class Solution {
public:
    int clumsy(int n) {
        stack<int> stk;
        stk.push(n);
        n--;
        int index = 0; 
        while (n > 0) {
            if (index % 4 == 0) {
                stk.top() *= n;
            } else if (index % 4 == 1) {
                stk.top() /= n;
            } else if (index % 4 == 2) {
                stk.push(n);
            } else {
                stk.push(-n);
            }
            n--;
            index++;
        }

        int result = 0;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};
