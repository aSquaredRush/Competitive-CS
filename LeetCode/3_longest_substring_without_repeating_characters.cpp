class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int maxlen = 0;
        int index = 0;
        set<char> s;
        bool boolean = true;
        int l,r; l = 0; r = 0;

        while(r<str.size()){
            if(s.find(str[r])!=s.end()){
                maxlen = max(r-l,maxlen);
                s.erase(str[l]);
                l++;
            }
            else{
                s.insert(str[r]);
                r++;
               
            }

        }
        maxlen = max((int)str.size()-l,maxlen);

        return maxlen;
    }
};