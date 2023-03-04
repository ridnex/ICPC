#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int dp[n];
    dp[0]=0;
    dp[1]=arr[1]-arr[0];
    dp[2]=arr[2]-arr[0];
    for(int i=3; i<n; i++){
        dp[i]=min(dp[i-1], dp[i-2])+ arr[i]-arr[i-1];
    }
    cout << dp[n-1];
}