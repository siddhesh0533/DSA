#include <iostream>
using namespace std;

class NStack {
    int *arr;      // Main array to store elements
    int *top;      // Array to store tops of N stacks
    int *next;     // Array to manage free spots and stack links
    int n, s;
    int freeSpot;

public:
    NStack(int N, int S) {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        for (int i = 0; i < n; i++)
            top[i] = -1;

        for (int i = 0; i < s - 1; i++)
            next[i] = i + 1;
        next[s - 1] = -1;

        freeSpot = 0;
    }

    bool push(int x, int m) {
        if (freeSpot == -1)
            return false;

        int index = freeSpot;
        freeSpot = next[index];

        arr[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;

        return true;
    }

    int pop(int m) {
        if (top[m - 1] == -1)
            return -1;

        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

int main() {
    int N = 3, S = 6;
    NStack ns(N, S);

    cout << (ns.push(10, 1) ? "True" : "False") << "\n"; // True
    cout << (ns.push(20, 1) ? "True" : "False") << "\n"; // True
    cout << (ns.push(30, 2) ? "True" : "False") << "\n"; // True

    cout << ns.pop(1) << "\n"; // 20
    cout << ns.pop(2) << "\n"; // 30
    cout << ns.pop(3) << "\n"; // -1

    return 0;
}
