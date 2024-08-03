

#ifndef COMP_LEETCODEBITS_H
#define COMP_LEETCODEBITS_H

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define fr(i,a) FOR(i,0,a)


#define fast ios::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define vl vector<ll>
#define vi vector<int>
#define vvi vector<vi>

#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define pb(a) push_back(a)
#endif //COMP_LEETCODEBITS_H

class Solution {
public:
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
};