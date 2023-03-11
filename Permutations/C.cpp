#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> permut(int n, vector<int>arr){
    int i=n-2;
    for(i; i>=0; i--){
        if(arr[i]<arr[i+1]){
            break;
        }
    }
    if(i<0){
        reverse(arr.begin(), arr.end());
    }
    else{
        int k = n-1;
        for(k; k>i; k--){
            if(arr[k]>arr[i]){
                break;
            }
        }
        swap(arr[i], arr[k]);
        reverse(arr.begin()+i+1, arr.end());
        
    }
    return arr;

}
int main(){
    // freopen("success.in", "r", stdin);
    // freopen("success.out", "w", stdout);
    int n; cin >> n;
    vector <int> arr;
    vector <int> barr;

    for(int i=0; i<n; i++){
        int l;
        cin >> l;
        arr.push_back(l);
    }
    
    
    arr = permut(n, arr);
    for(int i=0; i<n; i++){
        cout << arr.at(i)<<" ";
    }
}