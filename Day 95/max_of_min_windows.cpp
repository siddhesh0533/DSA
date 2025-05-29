#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Function to compute maximum of minimums for every window size
vector<int> maxOfMin(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n + 1, 0);        // Result for window sizes 1 to n
    vector<int> left(n), right(n);    // Arrays for previous and next smaller
    stack<int> s;

    // Compute Previous Smaller Element (PSE)
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Clear stack to reuse
    while (!s.empty()) s.pop();

    // Compute Next Smaller Element (NSE)
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Fill res[] such that res[len] is max of minimums for window size = len
    for (int i = 0; i < n; i++) {
        int len = right[i] - left[i] - 1;
        res[len] = max(res[len], arr[i]);
    }

    // Some entries in res[] might be 0, so fill them from right to left
    for (int i = n - 1; i >= 1; i--) {
        res[i] = max(res[i], res[i + 1]);
    }

    // We ignore index 0, as window sizes start from 1
    vector<int> answer(res.begin() + 1, res.end());
    return answer;
}

// Main function
int main() {
    vector<int> arr = {10, 20, 30, 50, 10, 70, 30};
    vector<int> result = maxOfMin(arr);

    cout << "Output: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
