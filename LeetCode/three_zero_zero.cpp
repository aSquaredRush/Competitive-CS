#include "leetcodebits.h"

int bin(vector<int> arr,int a){
    int lo = 0;
    int hi = arr.size()-1;
    int prev = INT_MAX;
    int mid;
    if(arr.size()==1&&arr[0]>a) return 0;
    if(a<arr[0]) return 0;
    while(lo<=hi){
        if(lo+1==hi&&arr[lo]<a&&arr[hi]>a) return hi;
        mid = lo + (hi-lo)/2;
        if(arr[mid]==a) return -1;
        if(arr[mid]<a) lo = mid;
        else if(arr[mid]>a) hi = mid;
    }
    return -1;

}
int lengthOfLIS(vector<int>& arr){
    int prev = INT_MIN;
    vector<int> final;
    fr(i,arr.size()){
        if(arr[i]>prev){
            final.push_back(arr[i]);
            prev = arr[i];
        }
        else if(arr[i]<prev){
            int index = bin(final,arr[i]);
            if(index!=-1) final[index] = arr[i];
            if(index==final.size()-1) prev = arr[i];
        }
//        cout << "prev: "<< prev <<"\n";
    }
//    fr(i,final.size()) cout << final[i]<<" ";
//    cout << "\n";
    return final.size();

}



int main(){
    fast;
    vector<int> arr;
//    arr.push_back(10);
//    arr.push_back(9);
//    arr.push_back(2);
//    arr.push_back(5);
//    arr.push_back(3);
//    arr.push_back(7);
//    arr.push_back(101);
//    arr.push_back(18);
    arr.push_back(1);
    arr.push_back(2);
//    arr.push_back(2);
//    arr.push_back(2);
//    cout << "index: " << bin(arr,2) << "\n";
     cout << lengthOfLIS(arr) << "\n";


    return 0;
}