#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> reverseFirstK(queue<int> q, int k) {
    if (q.empty() || k <= 0 || k > q.size()) return q;

    stack<int> s;

    // Step 1: Push first k elements into a stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue back the stack elements (reversed part)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move the remaining elements (n - k) to the back
    int remaining = q.size() - k;
    for (int i = 0; i < remaining; i++) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;
    queue<int> result = reverseFirstK(q, k);

    // Print the result
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }

    return 0;
}
