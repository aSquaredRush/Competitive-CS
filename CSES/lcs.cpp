

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
#define FOR(i, a, b) for(int i = (a); i<(b); i++)
#define fr(i, a) FOR(i,0,a)


#define fast ios::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define vl vector<ll>
#define vi vector<int>
#define vvi vector<vi>

#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define pb(a) push_back(a)
#endif //COMP_LEETCODEBITS_H


int main() {
    fast;
    string a, b;
    cin >> a >> b;

    vector<vector<long long>> v((b.size()+1),vector<long long> ((a.size()+1)));

    for (int i = 0; i <= b.size(); i++) {
        for (int j = 0; j <= a.size(); j++){
            if(i == 0 or j == 0) v[i][j] = 0;
        }
    }

    for (int i = 1; i <= b.size(); i++) {
        for (int j = 1; j <= a.size(); j++){
            if(b[i-1]==a[j-1]){
                v[i][j] = 1 + v[i-1][j-1];
            }
            else{
                v[i][j] = max(v[i-1][j],v[i][j-1]);
            }
        }
    }

    cout << v[b.size()][a.size()] <<"\n";

//    for(int i = 0;i<v.size();i++){
//        for(int j = 0;j<v[0].size();j++){
//            cout << v[i][j]<<" ";
//        }
//        cout << "\n";
//    }


    return 0;
}