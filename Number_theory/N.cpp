#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
long long Euler(long long n){
    long long cnt = n;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            while(n%i==0){
                n = n / i;
            }
            cnt *=  (1.0-(1.0/i));
            
        }
    }
    if(n>1){
        cnt -= (cnt/n);
    }
    return cnt;   
}
int main(){
    int m;
    cin >> m;
    long long arr[10005];
    arr[1]=1;
    for(long long i=2; i<=10000; i++){
            arr[i] = arr[i-1] + Euler(i);
    }
    for(int j=0; j<m; j++){
        long long n, cnt=1;
        cin >> n;
        cout << arr[n]*arr[n]<<endl;

    }
    
}