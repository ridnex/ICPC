#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int m;
    cin >> m;
    int arr2[m];
    for(int i=0; i<m; i++){
        cin >> arr2[i];
    }
    int dp[n+1][m+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 or j==0){
                dp[i][j]=0;
            }
            else{
                if(arr[i-1]==arr2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] =  max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }
    cout << dp[n][m];
}