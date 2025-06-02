#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> reverseQueue(queue<int> q) {
    stack<int> s;

    // Step 1: Push all elements from queue to stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Pop from stack and enqueue back to queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    return q;
}

int main() {
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    queue<int> reversed = reverseQueue(q);

    // Print the reversed queue
    while (!reversed.empty()) {
        cout << reversed.front() << " ";
        reversed.pop();
    }

    return 0;
}
