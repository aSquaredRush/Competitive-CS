#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0)
#define ll long long


class Solution {
public:
    int heightChecker(vector<int>& heights) {
        fast;
        vector<int> heights2 = heights;
        sort(heights.begin(),heights.end());
        int ans = 0;
        for(int i = 0;i<heights.size();i++){
            if(heights[i]!=heights2[i]) ans++;
        }
        return ans;
    }
};