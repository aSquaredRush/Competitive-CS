#include "leetcodebits.h"

map<char,vector<char>> wordMap;
long long recurse(int n, char ch){
    long long count = 0;
    if(n==1) return 1;
    else{
        fr(i,wordMap[ch].size()){
            count+=recurse(n-1,wordMap[ch][i]);
            count %= 1000000000+7;
        }
    }
    return count;

}


int countVowelPermutation(int n){
    wordMap['a'].push_back('e');
    wordMap['e'].push_back('a'); wordMap['e'].push_back('i');
    wordMap['i'].push_back('a'); wordMap['i'].push_back('e'); wordMap['i'].push_back('o'); wordMap['i'].push_back('u');
    wordMap['o'].push_back('i'); wordMap['o'].push_back('u');
    wordMap['u'].push_back('a');
    long long count = 0;
    for(auto& [tempChar,arr]:wordMap){
        count+= recurse(n,tempChar);
    }
    return count;
}
int main(){
    fast;
    int n; cin>>n;
    cout << countVowelPermutation(n)<<"\n";
    return 0;
}
