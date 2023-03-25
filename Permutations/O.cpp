#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    long long dp[n+1][k+1];
    dp[0][0]=0;
    dp[1][0]=1;
    dp[2][0]=1;
    dp[2][1]=1;
    for(int i=3; i<=n; i++){
        for(int j=0; j<=i*(i-1)/2;j++){
            dp[i][j]=0;
        }
    }
    for(int i=3; i<=n; i++){
        for(int j=0; j<=i*(i-1)/2;j++){
            if(k-j<=(i-1)*(i-2)/2){
                dp[i][j]+=dp[i-1][k-j];
            }
        }
    }
    cout << dp[n][k];

}
