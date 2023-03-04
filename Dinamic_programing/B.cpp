#include <iostream>
using namespace std;
int main(){
    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);
    int n;
    cin >> n;
    char arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int dp[n];
    dp[0] = 0;
    if(arr[1]=='w'){
        dp[1]=-1;
    }
    else{
        dp[1]=dp[0];
        if(arr[1]=='"'){
            dp[1]++;
        }
    }
    if(arr[2]=='w' or dp[1]==-1){
        dp[2]=-1;
    }
    else{
        dp[2]=dp[1];
        if(arr[2]=='"'){
            dp[2]++;
        }
    }
    if(arr[3]=='w'){
        dp[3]=-1;
    }
    else{
        dp[3]=max(dp[0], dp[2]);            
        if(arr[3]=='"'){
            dp[3]++;
        }
        
    }
    if(arr[4]=='w'){
        dp[4]=-1;
    }
    else{
        if(dp[3]==-1 && dp[1]==-1){
            dp[4]=-1;
        }
        else{
            dp[4]=max(dp[1], dp[3]);
            if(arr[4]=='"'){
                dp[4]++;
            }
        }
    }
    for(int i=5; i<n; i++){
        if(arr[i]!='w'){
            if(dp[i-1]==-1 && dp[i-3]==-1 && dp[i-5]==-1){
                dp[i]=-1;
            }
            else{
                dp[i]=max(dp[i-1], max(dp[i-3], dp[i-5]));
                if(arr[i]=='"'){
                    dp[i]++;
                }
            }
        }
        else{
            dp[i]=-1;
        }
    }
    cout << dp[n-1];
}