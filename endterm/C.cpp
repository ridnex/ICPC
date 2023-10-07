#include <iostream>
using namespace std;
int main(){
        int m;
        cin >> m;
        while(m--){
        int n;
        cin >> n;
        long long arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int dp[n];
        int max[n];
        dp[0]=1;
        for(int i=1; i<n; i++){
            dp[i]=1;
            for(int j=0; j<i; j++){
                if(arr[j]<arr[i] and dp[i]<dp[j]+1){
                    dp[i] = 1 + dp[j];
                }
            }
        }
        int maxii=0;
        for(int i=0; i<n; i++){
            if(maxii<dp[i]){
                maxii = dp[i];
                
            }
        }

        cout << maxii;
    }
}