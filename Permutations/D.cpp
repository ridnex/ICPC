#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> next_per(int n, vector<int>arr){
    int i=n-2;
    for(i; i>=0; i--){
        if(arr[i]>arr[i+1]){
            break;
        }
    }
    if(i<0){
        reverse(arr.begin(), arr.end());
    }
    else{
        int k = n-1;
        for(k; k>i; k--){
            if(arr[k]<arr[i]){
                break;
            }
        }
        swap(arr[i], arr[k]);
        reverse(arr.begin()+i+1, arr.end());
        
    }
    return arr;

}
int main(){
    // freopen("choose.in", "r", stdin);
    // freopen("choose.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> arr;
    vector<int> barr;
    for(int i=0; i<n; i++){
        if(i<m){
            arr.push_back(1);
        }
        else{
            arr.push_back(0);
        }
    }
    barr = arr;
    reverse(barr.begin(), barr.end());
    for(int i=0; i<n; i++){
        if(arr[i]==1){
            cout << i+1<<" ";
        }
    }
    cout << endl;
    while(barr!=arr){
        arr = next_per(n, arr);
        for(int i=0; i<n; i++){
            if(arr[i]==1){
                cout << i+1<<" ";
            }
        }
        cout << endl;
    }
}