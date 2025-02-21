class Solution {
    public:
        string reverseStr(string s, int k) {
            int n = s.length();
        
        for (int i = 0; i < n; i += 2 * k) {
            // Reverse first k characters in every 2k chunk
            if (i + k <= n) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
        }
        
        return s;
        }
    };