#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {}

    void push(int x) {
        // Step 1: Push to q2
        q2.push(x);

        // Step 2: Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: Swap q1 and q2
        swap(q1, q2);
    }

    int pop() {
        int top = q1.front();
        q1.pop();
        return top;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};
