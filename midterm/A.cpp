#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long n, k=-100000;
    cin >> n;
    vector<long long>arr;
    vector<long long>dp(n);
    for(int i=0; i<n; i++){
        int l;
        cin >> l;
        arr.push_back(l);
    }
    dp[0]=arr[0];
    for(int i=1; i<n; i++){
        dp[i]=max(dp[i-1]+arr[i], arr[i]);  
        if(dp[i]>=k){
            k= dp[i];
        }
    }
    cout << k;
}