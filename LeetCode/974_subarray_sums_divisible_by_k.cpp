#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0)
#define ll long long

class Solution {
public:
    int mod(int a, int b){
        if(a<0) return (b+(a)%b)%b;
        else return a%b;
    }

    int subarraysDivByK(vector<int>& nums, int k) {
        fast;
        vector<ll> sums;
        ll sum = 0;
        map<int, int> m;
        m.insert(make_pair(0,0));
        m.insert(make_pair(1,0));
        m.insert(make_pair(2,0));
        m.insert(make_pair(3,0));
        m.insert(make_pair(4,0));
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            int modsum = mod(sum,k);
            m[modsum]++;
        }
        long long ans = 0;
        for(auto a :m){
            long long tempans = 0;
            if(a.first==0) tempans+=a.second;
            tempans += a.second*(a.second-1)/2;
            ans +=tempans;
        }

        return ans;
    }

};
