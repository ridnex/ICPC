#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int dp[n];
    dp[0]=1;
    dp[1]=3;
    for(int i=2; i<=n; i++){
        dp[i] = 2 * dp[i-1] + 2;
        for(int j=i-2;j>=1;j--){
            dp[i] += dp[j];
        }
    }
    cout << dp[n];
}