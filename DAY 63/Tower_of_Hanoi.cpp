#include <iostream>
#include <cmath>
using namespace std;

void toh(int n, int sour, int help, int dest) {
    if (n == 1) {
        cout << "move disk " << n << " from rod " << sour << " to rod " << dest << endl;
        return;  // Fix: Ensure function returns for base case
    }

    toh(n - 1, sour, dest, help);  // Move n-1 disks from source to helper
    cout << "move disk " << n << " from rod " << sour << " to rod " << dest << endl;
    toh(n - 1, help, sour, dest);  // Move n-1 disks from helper to destination
}

int towerOfHanoi(int n, int from, int to, int aux) {
    toh(n, from, aux, to);
    return pow(2, n) - 1;  // Total moves required for Tower of Hanoi
}

int main() {
    int n = 3;
    cout << "Total moves required: " << towerOfHanoi(n, 1, 3, 2) << endl;
    return 0;
}
