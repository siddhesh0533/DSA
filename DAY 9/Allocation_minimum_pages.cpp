#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the minimum number of maximum pages allocated
int findPages(vector<int> &arr, int k) {
    int N = arr.size();
    if (k > N || N == 0) // Edge case: More students than books or no books
        return -1;

    int start = 0, end = 0, mid, ans;
    for (int i = 0; i < N; i++) {
        start = max(start, arr[i]); // Minimum possible pages (largest single book)
        end += arr[i];             // Maximum possible pages (sum of all books)
    }

    while (start <= end) {
        mid = start + (end - start) / 2;
        int pages = 0, count = 1; // Count of students required

        for (int i = 0; i < N; i++) {
            pages += arr[i];
            if (pages > mid) {
                count++;
                pages = arr[i]; // Reset pages for the next student
            }
        }

        if (count <= k) { // If allocation is valid
            ans = mid;    // Store the current answer
            end = mid - 1; // Try for a smaller maximum
        } else {
            start = mid + 1; // Try for a larger maximum
        }
    }
    return ans;
}

int main() {
    int n, k;
    cout << "Enter the number of books: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the number of pages in each book: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the number of students: ";
    cin >> k;

    int result = findPages(arr, k);
    if (result == -1) {
        cout << "Books cannot be allocated to all students.\n";
    } else {
        cout << "The minimum number of maximum pages allocated is: " << result << "\n";
    }

    return 0;
}
