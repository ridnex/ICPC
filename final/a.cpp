#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;
int mark[2000000];
int dp[2000000];
int Sum[2000000];
int Euler[2000005];

int Euler_fun(long long int n){
    while(n!=0){
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
}
#define GET(x) (mark[(x)>>5]>>((x)&31)&1)
#define SET(x) (mark[(x)>>5] |= 1<<((x)&31))

int main(){
    int t;
    cin >> t;
    dp[1]=0;
    Sum[1]=1;
    for(int i = 2; i <= 2000000; i++){
        Euler[i] = i;
    }
    register int i, j;
    SET(1);
    int n = 2000000;
    for(i = 2; i <= n; i++) {
        if(!GET(i)) {
            for(j = i; j <= n; j += i) {
                Euler[j] = Euler[j]/i*(i-1);
                SET(j);
            }
        }
    }
    for(long long i=2; i<=2000000; i++){
        dp[i] = dp[Euler[i]]+1;
        Sum[i]= Sum[i-1]+dp[i];
    }
    while(t--){
        long long int a, b;
        cin >> a >> b;
        cout << Sum[b]-Sum[a-1]<<endl;
    }
}