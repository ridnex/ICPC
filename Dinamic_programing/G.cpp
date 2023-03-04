#include <iostream>
using namespace std;
int main(){
    freopen("longpath.in", "r", stdin);
    freopen("longpath.out", "w", stdout);
    long long n, m,  maxii = 0;
    cin >> n >> m;
    int dp[n];
    for(int i=0; i<n; i++){
        dp[i]=0;
    }
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        dp[b-1] = max(dp[b-1], dp[a-1]+1);
        if(dp[b-1]>maxii){
            maxii = dp[b-1];
        }
    }
    cout << maxii;
}