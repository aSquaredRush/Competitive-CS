#include "leetcodebits.h"

vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    map<map<char,int>,string> set1;
    set<map<char,int>> set2;
    for(string str:words1){
        map<char,int> tempMap;
        fr(i,str.length()){
            tempMap[str[i]]++;
        }
        set1.insert({tempMap,str});
    }

    for(string str:words2){
        map<char,int> tempMap2;
        fr(i,str.length()){
            tempMap2[str[i]]++;
        }
        set2.insert(tempMap2);
    }


    vector<string> final;


    for(auto [tempMap, str] : set1){
        bool boolean = true;
        for(map tempMap2: set2){
            for(auto& [tempChar2, tempVal2]:tempMap2){
                if(tempMap.count(tempChar2)==0 || tempVal2>tempMap.at(tempChar2)) boolean = false;
            }
        }

        if(boolean){
            final.push_back(str);
        }
    }
    return final;

}

int main(){
    fast;

    vector<string> words1;
    vector<string> words2;

    words1.push_back("amazon"); words1.push_back("apple"); words1.push_back("facebook"); words1.push_back("google"); words1.push_back("leetcode");
    words2.push_back("e"); words2.push_back("l");

    vector<string> final = wordSubsets(words1,words2);

    fr(i,final.size()) cout << final[i] << "\n";

    return 0;
}
