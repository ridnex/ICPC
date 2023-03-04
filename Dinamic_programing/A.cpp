#include <iostream>
using namespace std;
int main(){
    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout);
    int n;
    cin >> n;
    long long arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int dp[n];
    dp[0] = 0;
    dp[1] = arr[0];
    for(int j=2; j<=n; j++){
        dp[j]=max(dp[j-1], dp[j-2])+arr[j-1];
    }
    cout << dp[n]<<endl;

}