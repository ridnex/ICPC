#include <iostream>
using namespace std;
int main(){
    freopen("king2.in", "r", stdin);
    freopen("king2.out", "w", stdout);
    int arr[8][8];
    int dp[8][8];
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=7; i>=0; i--){
        for(int j=0; j<8; j++){
            if(i==7 and j==0){
                dp[7][0]=0;
            }
            else if(i==7){
                dp[7][j]=dp[7][j-1]+arr[7][j];
            }
            else if(j==0){
                dp[i][0]=dp[i+1][0]+arr[i][0];
            }
            else{
                dp[i][j] = arr[i][j] + min(dp[i+1][j], min(dp[i+1][j-1], dp[i][j-1]));
            }
        }
    }
    cout << dp[0][7];
}