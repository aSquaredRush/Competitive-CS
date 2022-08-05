

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

long long exp(long long a,long long b,long long c){
    long prod = 1;
    while(b>0){
        if((b&1)==1){
            prod = (prod*a)%(c);
        }
        b = b>>1;
        a = (a*a)%(c);
    }
    return prod;


}

int main(){
    fast;

    int cases; cin>> cases;
    while(cases-->0){
        int a, b, c; cin>> a>>b>>c;
        cout << exp(a,exp(b,c,1000000000+6),100000000+7)<<"\n";

    }

    return 0;

}