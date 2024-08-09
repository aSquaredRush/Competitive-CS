class Solution {
public:


    string longestPalindrome(string s){
        int l,r;
        int maxl,maxr;
        maxl = 1; maxr = 0;
        string palindrome = "";
        for(int i = 0;i<s.size();i++){
            l = i; r = i;
            while(l>=0 and r<s.size()){
                if(s[l]==s[r]){
                    if(r-l+1>maxr-maxl+1){
                        maxl = l; maxr = r;
                    }
                    l--; r++;
                    
                }
                else break;
                
            }
            // cout <<"1. "<<i<<" "<< s.substr(maxl,maxr-maxl+1)<<"\n";
            l = i; r = i+1;
            while(l>=0 and r<s.size()){
                if(s[l]==s[r]){
                    if(r-l+1>maxr-maxl+1){
                        maxl = l; maxr = r;
                    }
                    l--; r++;
                }
                else break;
            }
            // cout <<"2. "<<i<<" "<< s.substr(maxl,maxr-maxl+1)<<"\n";

        }
        return s.substr(maxl,maxr-maxl+1);
    }};