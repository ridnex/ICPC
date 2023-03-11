#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n; 
    cin >> n;
    vector<int>arr;
    vector<int>barr;
    vector<int>carr;
    for(int i=0; i<n; i++){
        int l;
        cin >> l;
        arr.push_back(l);
        barr.push_back(i+1);
    }
    reverse(arr.begin(), arr.end());
    reverse(barr.begin(), barr.end());
    for(int i=0; i<n; i++){
        carr.push_back(barr[arr[i]]);
        barr.erase(barr.begin() + arr[i]);
    }
    for(int i=n-1; i>=0; i--){
        cout << carr[i]<<" ";
    }
}