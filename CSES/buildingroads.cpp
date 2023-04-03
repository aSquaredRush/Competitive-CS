

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

struct DSU{
    vector<int> parents;
    vector<int> setSize;
    int numSets;

    DSU(int N){
        parents = vector<int>(N,0);
        setSize = vector<int>(N,1);
        numSets = N;
        for(int i=0;i<N;i++) {
            parents[i]=i;
        }
    }
    int find(int i){
        return parents[i] ==i ? i:(parents[i] = find(parents[i]));
    }
    bool isSameSet(int i, int j){
        return find(i)==find(j);
    }
    void unite(int i, int j){
        if(isSameSet(i,j)) return;
        numSets--;
        i = find(i);
        j = find(j);
        if (i != j) {
            if (setSize[i] < setSize[j])
                swap(i, j);
            parents[j] = i;
            setSize[i] += setSize[j];
        }

    }
    int numDisjointSets(){
        return numSets;
    }
    int sizeOfSet(int i){
        return setSize[find(i)];
    }




};


int main(){
    fast;
    int cities, roads; cin>>cities>>roads;

    DSU dsu = DSU(cities);
//    for(int i = 0;i<cities;i++){
////        cout << dsu.parents[i]<<"\n";
//    }
//    cout <<"bob "<<dsu.find(0)<<"\n";
//    cout <<"bob "<<dsu.find(1)<<"\n";
    for(int i= 0;i<roads;i++){
        int a, b; cin>>a>>b;
//        cout << a<< " "<<b<<"\n";
        dsu.unite(a-1,b-1);
    }

    unordered_set<int> set;
    for(int i = 0;i<dsu.parents.size();i++){
        set.emplace(dsu.parents[i]);
    }
    cout << dsu.numDisjointSets()-1<<"\n";
    int x;
    int i = 0;
    for(int a : set){
        if(i==0){
            x = a;
            i++;
        }
        else{
            cout << x+1 << " "<<a+1<<"\n";
        }
    }


    return 0;
}