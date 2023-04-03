

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

ll MOD = (1<<31)-1;


long long fast_power(long long base, long long power) {
    long long result = 1;
    while(power > 0) {

        if(power&1 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power>>=1;// Can also use power >>= 1; to make code even faster
    }
    return result;
}



int letter(char x){
    return x-96;
}

vector<ll> v1(1);
vector<ll> v2(1);

long long hasher(string str, int b){
    long long x = 0;

    for(int i = 0;i<str.size();i++){
        ll a = (letter(str[i])*fast_power(b,i))%MOD;
        x+=a;
        if(b==7) v1.push_back(x);
        if(b==11) v2.push_back(x);
    }
    return x;


}

long long substring(int i, int j, int b){
    if(b==7){
        return (v1[j+1]-v1[i-1]);
    }
    else if(b==11){
        return (v2[j+1]-v2[i-1]);
    }

}

int main(){
    fast;
    string str; cin>>str;
    ll hash1 = hasher(str,7);
//    ll hash2 = hasher(str,11);
    for(int i = 1;i<=str.length();i++){
        string prefix = str.substr(0,i);
        ll comp1 = substring(1,i-1,7);
//        ll comp2 = substring(1,i-1,11);
        bool boolean = true;
        for(int j = 0;j<=str.length()-i;j+=i){
            ll test1 = substring(j+1,j+i-1,7);
//            ll test2 = substring(j+1,j+i-1,11);
            if(comp1 *fast_power(7,j) != test1 /*or comp2 *pow(11,j)!= test2*/){
                boolean = false;
                break;
            }
        }
        if(boolean){
            int x = str.length()-prefix.length();
            ll a1 = substring(1,x-1,7);
            ll b1 = substring(prefix.length()+1,prefix.length()+x-1,7);
//            ll a2 = substring(1,x-1,11);
//            ll b2 = substring(prefix.length()+1,prefix.length()+x-1,11);
            if(a1* fast_power(7,prefix.length())==b1 /*and (a2*pow(11,prefix.length())==b2)*/){
                if(i==str.length()) cout <<prefix.length()<<"\n";
                else cout << prefix.length() <<" ";
            }
        }
    }

    return 0;
}