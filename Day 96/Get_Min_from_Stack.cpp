#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Global stacks
stack<int> mainStack;
stack<int> minStack;

// Push an element onto the stack
void push(int x) {
    mainStack.push(x);
    if (minStack.empty() || x <= minStack.top()) {
        minStack.push(x);
    }
}

// Pop the top element
void pop() {
    if (!mainStack.empty()) {
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }
}

// Return the top element
int peek() {
    if (mainStack.empty()) return -1;
    return mainStack.top();
}

// Return the minimum element
int getMin() {
    if (minStack.empty()) return -1;
    return minStack.top();
}

// Driver code
int main() {
    int q;
    cin >> q;  // number of queries
    vector<int> output;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            push(x);
        } else if (type == 2) {
            pop();
        } else if (type == 3) {
            output.push_back(peek());
        } else if (type == 4) {
            output.push_back(getMin());
        }
    }

    // Print the results of peek() and getMin()
    for (int val : output) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
