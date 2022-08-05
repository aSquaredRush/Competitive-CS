//TLE

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
}#include <utility>
#include <valarray>

#include <vector>
#if __cplusplus >= 201103L


int gcd(int a, int b){
    if(max(a,b)%min(a,b)==0) return min(a,b);
    return gcd(min(a,b),max(a,b)%min(a,b));
}

int main(){
    fast;
    int x; cin >> x;
    vector<int> arr;
    fr(i,x){
        int temp; cin >> temp;
        arr.push_back(temp);
    }
    int maxGCD = -5;
    fr(i,arr.size()){
        for(int j=i+1;j<arr.size();j++){
//            cout << arr[i] << " " << arr[j] << " "<<gcd(arr[i],arr[j])<< "\n";
            maxGCD = max(maxGCD,gcd(arr[i],arr[j]));
        }
    }
    cout << maxGCD << "\n";
    return 0;
}
