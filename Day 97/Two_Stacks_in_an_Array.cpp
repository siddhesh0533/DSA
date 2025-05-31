#include <iostream>
using namespace std;

class TwoStacks {
    int *arr;
    int top1, top2;
    int size;

public:
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int x) {
        if (top1 + 1 < top2) {
            arr[++top1] = x;
        }
    }

    void push2(int x) {
        if (top1 + 1 < top2) {
            arr[--top2] = x;
        }
    }

    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        }
        return -1;
    }

    int pop2() {
        if (top2 < size) {
            return arr[top2++];
        }
        return -1;
    }
};

int main() {
    TwoStacks ts(10);

    ts.push1(2);
    ts.push1(3);
    ts.push2(4);

    cout << ts.pop1() << " ";  // Output: 3
    cout << ts.pop2() << " ";  // Output: 4
    cout << ts.pop2() << "\n"; // Output: -1

    return 0;
}
