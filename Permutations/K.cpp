#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    
    int arr[n];
    int maxi=-10000;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
    }
    long long dp_factorial[maxi+1], output=0;

    dp_factorial[0]=1;
    for(int i=1; i<=maxi; i++){
        dp_factorial[i] = dp_factorial[i-1]*i;
    } 
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=i+1;j<n; j++){
            if(arr[i]>arr[j]){
                cnt++;
            }
        }
        // cout << arr[i]<< " "<< cnt<<endl;
        output+=cnt*dp_factorial[n-i-1];
    }
    cout << output+1;
}