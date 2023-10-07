#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    long long dp[n][m];
    if((n+m)%3!=2){
        cout << 0 ;
        return 0;
    }
    if(m>2*n or n>2*m){
        cout << 0 ;
        return 0;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if((i+j)%3==0){
                if(i==0 and j==0){
                    dp[i][j]=1;
                }
                else{
                        dp[i][j]=0;
                    }
                    if (i-1>=0 and j-2>=0){
                        dp[i][j]+=dp[i-1][j-2];
                    }
                    if (i-2>=0 and j-1>=0){
                        dp[i][j]+=dp[i-2][j-1];
                    }                
                }
            else{
                dp[i][j]=0;
            }
        }
    }
    cout << dp[n-1][m-1];
}
