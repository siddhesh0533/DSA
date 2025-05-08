#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find next smaller element to the right (non-circular)
vector<int> nextSmallerElement(vector<int> &arr, int n) {
    vector<int> ans(n, -1);
    stack<int> st; // stack to store indices

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            ans[i] = arr[st.top()];
        }

        st.push(i);
    }

    return ans;
}

int main() {
    int t;
    cin >> t;  // number of test cases

    while (t--) {
        int n;
        cin >> n; // size of the array
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> result = nextSmallerElement(arr, n);

        for (int x : result) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
