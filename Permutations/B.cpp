#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    // freopen("inverse.in", "r", stdin);
    // freopen("inverse.out", "w", stdout);
    int n; cin >> n;
    vector <int> arr(n, 0);

    for(int i=1; i<=n; i++){
        int l;
        cin >> l;
        arr[l-1]=i;
    }
    for(int j=0; j<n; j++){
        cout << arr[j]<<" ";
    }
    

}