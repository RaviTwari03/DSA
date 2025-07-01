class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {}

    void push(int x) {
        q2.push(x);
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Swap q1 and q2
        swap(q1, q2);
    }

    int pop() {
        if (!q1.empty()) {
            int topElem = q1.front();
            q1.pop();
            return topElem;
        }
        return -1; // stack is empty
    }

    int top() {
        if (!q1.empty()) return q1.front();
        return -1; // stack is empty
    }

    bool empty() {
        return q1.empty();
    }
};