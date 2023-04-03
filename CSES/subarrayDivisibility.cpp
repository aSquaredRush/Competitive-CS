

#ifndef COMP_CFBITS_H
#define COMP_CFBITS_H

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
#include <cstdio>
#include<stdio.h>
#include<stdlib.h>
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


int main(){
//    freopen("/Users/pankajchaubey/Downloads/subarrayDivisibility.in", "r", stdin);
    fast;
    int n; cin>>n;
    vector<int> arr(n);
    vector<int> sumarr(n+1);
    sumarr[0] = 0;
    int count = 0;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        count+=arr[i];
        count%=n;
        if(count<0) count=n+count;
        sumarr[i+1] = count;
    }
    std::map<int,long long> map;
    for(int i =1; i<=n;i++){
        map[sumarr[i]]++;
    }
    for(int i = 0;i<sumarr.size();i++){
        cout << sumarr[i] << " ";
    }
    cout <<"\n";
    long long ans = 0;
    for(auto [key,val]:map){
//        cout<< key<< " "<<val<<"\n";
        if(key==0){
            ans+=val;
        }
//        cout << "ans1: "<<ans<<"\n";
        if(val>1){
//            cout << "val: "<<val<<"\n";
            ans += val*(val-1)/2;
//            cout << val*(val-1)/2<<"\n";
        }
//        cout << "ans2: "<<ans<<"\n";
    }
    cout << ans<<"\n";


    return 0;
}

/*
  6
  0 0 0 0 0 0

 */