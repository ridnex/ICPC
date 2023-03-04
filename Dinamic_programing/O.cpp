#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string qwe, wer;
    cin >> qwe;
    
    
    n = qwe.size();

    char arr[n];
    for(int i=0; i<n; i++){
        arr[i] = qwe[i];
    }
    int m;
    cin >> wer;
    m = wer.size();
    char arr2[m];
    for(int i=0; i<m; i++){
        arr2[i]=wer[i];
    }
    int dp[n+1][m+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 or j==0){
                dp[i][j]=0;
            }
            else{
                if(arr[i-1]==arr2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] =  max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }
    int  a=n, b= m, maxi = dp[n][m];
    char arr3[maxi+1];
    arr3[maxi]='\0';
    while(a>0 and b>0){
        if(arr[a-1]==arr2[b-1]){
            arr3[maxi-1]=arr[a-1];
            a--;
            b--;
            maxi--;
        }
        else{
            if(dp[a-1][b] > dp[a][b-1]){
                a--;
            }
            else{
                b--;
            }
        }
    }
    for(int i=0; i<dp[n][m]; i++){
        cout<< arr3[i];
    }
    
}