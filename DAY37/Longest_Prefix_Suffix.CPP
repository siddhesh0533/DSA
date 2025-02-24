class Solution {
    public:
        int longestPrefixSuffix(string &s) {
            int n = s.size();
            vector<int> lps(n, 0);
            
            int len = 0; // Length of previous longest prefix suffix
            int i = 1;
            
            while (i < n) {
                if (s[i] == s[len]) {
                    len++;
                    lps[i] = len;
                    i++;
                } else {
                    if (len != 0) {
                        len = lps[len - 1]; // Backtrack
                    } else {
                        lps[i] = 0;
                        i++;
                    }
                }
            }
            
            return lps[n - 1]; // Last value in LPS array
        }
    };
    