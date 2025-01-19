int trap(vector<int>& height) {
    if (height.empty()) return 0; // If the array is empty, no water can be trapped.
    
    int left = 0, right = height.size() - 1; // Two pointers
    int leftMax = 0, rightMax = 0; // Track maximum heights
    int waterTrapped = 0; // Result variable to store trapped water
    
    while (left <= right) {
        if (height[left] <= height[right]) {
            // Process the left pointer
            if (height[left] >= leftMax) {
                leftMax = height[left]; // Update leftMax
            } else {
                waterTrapped += leftMax - height[left]; // Calculate trapped water
            }
            left++; // Move the left pointer
        } else {
            // Process the right pointer
            if (height[right] >= rightMax) {
                rightMax = height[right]; // Update rightMax
            } else {
                waterTrapped += rightMax - height[right]; // Calculate trapped water
            }
            right--; // Move the right pointer
        }
    }
    
    return waterTrapped; // Return the total trapped water
}
