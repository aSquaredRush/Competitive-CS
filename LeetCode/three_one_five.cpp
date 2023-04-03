
#include "leetcodebits.h"

int bsearch(vector<int> arr, int i,int j,int val){
    int lo = i;
    int hi = j;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(arr[mid]>=val){
            if(mid-1>=0 && arr[mid-1]<val) return mid-1;
            hi = mid-1;
//            if(val==1) cout << lo << " "<< hi << "\n";
        }
        else if(arr[mid]<val){
            if(mid+1<arr.size() && arr[mid+1]>=val) return mid;
            else lo = mid+1;
        }

    }
        if(hi<0) return -1;
        else if(lo>=arr.size()) return arr.size()-1;
        else return 0;
}
int main(){
    fast;
    vector<int> arr = {5,6,1,7,2};
    arr = {5,2,6,1};

    vector<int> final;
    fr(i,arr.size()-1) {
        vector<int> sorted;
        FOR(j,i+1,arr.size()) sorted.push_back(arr[j]);
        sort(sorted.begin(),sorted.end());
//        fr(j,sorted.size()) cout << sorted[j];
//        cout<< "\n";
//        cout << sorted.size() << " ";
//        cout << arr[i] << " ";
//        cout << bsearch(sorted,0,sorted.size()-1,arr[i])+1<<"\n";
        final.push_back(bsearch(sorted,0,sorted.size()-1,arr[i])+1);
    }
    final.push_back(0);
    fr(j,final.size()) cout << final[j];


    return 0;
}




