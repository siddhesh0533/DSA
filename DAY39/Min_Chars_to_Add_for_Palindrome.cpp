public:
    int minChar(string& s) {
        // Write your code here
        string rev= s;
        reverse(rev.begin(),rev.end());
        int size=s.size();
        s+='$';
        s+=rev;
        
        int n=s.size();
        vector<int>lps(n,0);
        
        int pre=0, suf=1;
        
        while(suf<s.size()){
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                pre++, suf++;
            }
            else{
                if(pre==0){
                    suf++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
    return size-lps[n-1];
    }