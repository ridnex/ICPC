#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    int v[n];
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(v[i]!=v[j] and arr[i][j]==1){
                cnt++;
            }
        }
    }
    cout << cnt;
}