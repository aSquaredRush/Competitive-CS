#include "leetcodebits.h"
//runtime 0ms faster than 100% of idiots on leetcode :)
vector <string> findAndReplacePattern(vector <string> &words, string pattern) {
        vector<string> arr;
        for (string str: words) {
            map<char, char> wordMap;
            set<char> used;
            for (int i = 0; i < pattern.length(); i++) {
                if (wordMap.count(pattern[i]) == 0 && used.count(str[i])==0){
                    wordMap[pattern[i]] = str[i];
                    used.insert(str[i]);
                }
                else {
                    if (wordMap[pattern[i]] != str[i]) break;
                }
                if (i == str.length() - 1) arr.push_back(str);
            }
        }
        return arr;


}


int main() {
    fast;
    vector<string> words;
    words.push_back("abc");
    words.push_back("deq");
    words.push_back("mee");
    words.push_back("aqq");
    words.push_back("dkd");
    words.push_back("ccc");
    string pattern = "abb";
    vector<string> final = findAndReplacePattern(words,pattern);
    for(string str:final) cout << str << " "<< pattern << "\n";
    return 0;
}


