

#ifndef COMP_CSES_H
#define COMP_CSES_H

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
#endif //COMP_CSES_H


int main() {
    fast;
    int x, sum;
    cin >> x >> sum;
    vector<long long> nums(x, 0);
    vector<long long> dp(sum + 1, 0);
    fr(i, x) cin >> nums[i];
    dp[0] = 1;
    fr(j, nums.size()) {
        fr(i, dp.size()) {
            if (i - nums[j] >= 0) dp[i] += dp[i - nums[j]];
            dp[i] = dp[i] % (1000000000+7);
        }

    }
//    fr(i,dp.size()) cout << i<< " "<< dp[i] <<"\n";
    cout << dp[sum];


    return 0;
}


int main(){
    fast;
    int pairs;
    cin >> pairs;
    vector<pair<int,int>>* movies = new vector<pair<int,int>>;
    while(pairs-->0){
        int a, b;
        cin >> a >> b;
        movies->emplace_back(make_pair(b,a));
    }
    sort(movies->begin(),movies->end());
    int count = 1;
    int currEnd = movies->at(0).first;
    for(int i = 1;i<movies->size();i++){
        if(movies->at(i).second>=currEnd){
            count++;
            currEnd = movies->at(i).first;
        }
    }
    cout << count;



    return 0;
}
