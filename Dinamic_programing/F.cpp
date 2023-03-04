#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector <int>dp(300001, 300002);
    for(int i=0; i<dp.size(); i++){
        for(int j=1; j<121; j++){
            long long k = j*(j+1)*(j+2)/6;
            dp[k]=1;
            if(i>=k){
                dp[i] = min(dp[i-k]+1, dp[i]);
            }
        }
    }
    freopen("balls.in", "r", stdin);
    freopen("balls.out", "w", stdout);
    int t;
    cin >> t;
    for(int i=0; i<t;i++){
        int a;
        cin >> a;
        cout << dp[a]<<endl;
    }
}