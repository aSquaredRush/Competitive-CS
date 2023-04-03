

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

int bsearch(vector<int> v, int a){
    int lo, hi; lo = 0; hi = v.size()-1;
    int mid = lo +(hi-lo)/2;
    while(v[mid]!=a){
        mid = lo +(hi-lo)/2;
        if(v[mid] == a) return mid;
        else if(v[mid]<a) hi = mid;
        else if(v[mid]>a) lo = mid;
        if(lo==mid &&lo == hi && v[mid]!=a) return -1;
    }

}



int main() {
    fast;
    int tickets, people;
    cin >> tickets >> people;
    vector<int> t(tickets);
    vector<int> p(people);
    for (int i = 0; i < tickets; i++) cin >> t[i];
    for (int i = 0; i < people; i++) cin >> p[i];

    sort(t.begin(),t.end());

    for(int i = 0;i<p.size();i++){
        int x = bsearch(t,p[i]);
        if(x!=-1) t.erase(t.begin()+x);
        cout << x <<"\n";
    }






    return 0;
}