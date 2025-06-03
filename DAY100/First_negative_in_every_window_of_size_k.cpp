#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegativeInWindow(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> result;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        // Remove out-of-window elements
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Add current element if it's negative
        if (arr[i] < 0)
            dq.push_back(i);

        // Append result after the first (k - 1) elements
        if (i >= k - 1) {
            if (!dq.empty())
                result.push_back(arr[dq.front()]);
            else
                result.push_back(0);
        }
    }

    return result;
}

int main() {
    vector<int> arr1 = {-8, 2, 3, -6, 10};
    int k1 = 2;
    vector<int> arr2 = {12, -1, -7, 8, -15, 30, 16, 28};
    int k2 = 3;
    vector<int> arr3 = {12, 1, 3, 5};
    int k3 = 3;

    vector<vector<int>> results = {
        firstNegativeInWindow(arr1, k1),
        firstNegativeInWindow(arr2, k2),
        firstNegativeInWindow(arr3, k3)
    };

    for (const auto& res : results) {
        for (int x : res)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
