#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    int dp[n];
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    dp[0]=0;
    dp[1]=abs(arr[1]-arr[0]);
    for(int i=2; i<n; i++){
        dp[i] = min(dp[i-2]+ abs(arr[i-2]-arr[i]), dp[i-1]+ abs(arr[i-1]-arr[i]));
    }
    cout << dp[n-1];
}