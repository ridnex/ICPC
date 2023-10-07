#include <iostream>
using namespace std;
int main(){
    int n, m, ans=0;
    cin >> n >> m;
    int arr[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j]=0;
        }
    }
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        arr[a-1][b-1]=1;
        arr[b-1][a-1]=1;

    }
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(arr[i][j]==1){
                cnt++;
            }
        }
        if(cnt==1){
            ans++;
        }
    }
    cout << ans;
}