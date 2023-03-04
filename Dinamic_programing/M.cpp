#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n>> m;
    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    int dp[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 and j==0){
                dp[0][0] =arr[0][0];
            }
            else if(i-1<0 ){
                dp[i][j] = dp[i][j-1] + arr[i][j];
            }
            else if(j-1<0 ){
                dp[i][j] = dp[i-1][j] + arr[i][j];
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
            }
            cout << dp[i][j]<< " ";
        }
        cout << endl;
    }
    
}