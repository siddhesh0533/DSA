class Solution {
public:
    bool isPerfectSquare(int num) {
        

        int low = 1, high = num;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid > num / mid) {  
                high = mid - 1;
            } else if (mid * mid == num) {  
                return true;
            } else {
                low = mid + 1;
            }
        }
        return false;  
    }

    
};