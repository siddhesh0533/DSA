#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inStack, outStack;

    // Transfer elements only when outStack is empty
    void transferInToOut() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        transferInToOut();
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek() {
        transferInToOut();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
