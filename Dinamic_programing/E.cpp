#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> arr[i][j];
        }
    }
    int dp[n][n];
    long long maxii = -100000000;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            if(i==0 and j==0){
                dp[0][0]=arr[0][0];
            }
            else if(j==0){
                dp[i][0]=dp[i-1][0]+arr[i][0];
            }
            else if(i==j){
                dp[i][j]=dp[i-1][j-1]+arr[i][j];
            }
            else{
                dp[i][j]=arr[i][j]+max(dp[i-1][j], dp[i-1][j-1]);
            }
            if(i==n-1 and dp[i][j]>=maxii){
                maxii=dp[i][j];

            }
        }
    }


    cout << maxii;
    
}