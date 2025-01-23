#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) return result;

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int i = left; i <= right; ++i) {
            result.push_back(matrix[top][i]);
        }
        top++; // Move the top boundary down

        // Traverse from top to bottom
        for (int i = top; i <= bottom; ++i) {
            result.push_back(matrix[i][right]);
        }
        right--; // Move the right boundary left

        if (top <= bottom) {
            // Traverse from right to left
            for (int i = right; i >= left; --i) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--; // Move the bottom boundary up
        }

        if (left <= right) {
            // Traverse from bottom to top
            for (int i = bottom; i >= top; --i) {
                result.push_back(matrix[i][left]);
            }
            left++; // Move the left boundary right
        }
    }

    return result;
}
