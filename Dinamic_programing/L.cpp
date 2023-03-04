#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    int dp[n+1];
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
   
    for(int i=4; i<=n; i++){
        dp[i]=100000;
        for(int j=sqrt(i)+1; j>=2; j--){
            if(i%j==0){
                dp[i] = min(dp[i], dp[j]+dp[i/j]);
            }
        }
        for(int k=1; k*2<=i; k++){
            dp[i] = min(dp[i], dp[k]+dp[i-k]);
        }
    }
    cout << dp[n];
    // for(int i=1; i<5000; i++){
    //     cout <<i << " " << dp[i]<< endl;
    // }
}