#include <bits/stdc++.h>
using namespace std;

string solve(string A) {
    vector<int> freq(26, 0); // Frequency of characters
    queue<char> q; // Queue to track potential first non-repeating characters
    string B = "";

    for (char ch : A) {
        freq[ch - 'a']++;     // Increment frequency
        q.push(ch);           // Push current character to the queue

        // Remove characters from the front if they're repeating
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        // Append first non-repeating character or '#' if none
        if (q.empty())
            B += '#';
        else
            B += q.front();
    }

    return B;
}

int main() {
    string A1 = "abadbc";
    string A2 = "abcabc";

    cout << "Input: " << A1 << "\nOutput: " << solve(A1) << "\n\n";
    cout << "Input: " << A2 << "\nOutput: " << solve(A2) << "\n";

    return 0;
}
