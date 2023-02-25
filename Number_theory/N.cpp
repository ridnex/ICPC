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
    for(int j=0; j<m; j++){
        long long n, cnt=1;
        cin >> n;
        vector <long long> u(n+1, 0);
        for(long long i=2; i<n+1; i++){
            if(u[i]==0){
                for(long long j=(i)*(i); j<n+1;j+=(i) ){
                    u[j]=1;   
                }
                cnt += i-1;
            }
            else{
                cnt += Euler(i);
            }  
        }
        cout << cnt*cnt<<endl;

    }
    
}