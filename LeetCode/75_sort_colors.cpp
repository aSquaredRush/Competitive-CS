#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0)
#define ll long long

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a,b,c;
        a = 0; b = 0; c = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0) a++;
            else if(nums[i]==1) b++;
            else if(nums[i]==2) c++;
        }

        vector<int> ans;

        for(int i = 0;i<a;i++){
            ans.emplace_back(0);
        }
        for(int i = 0;i<b;i++){
            ans.emplace_back(1);
        }
        for(int i = 0;i<c;i++){
            ans.emplace_back(2);
        }
        nums = ans;
    }
};