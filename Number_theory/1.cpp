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
    for(int i=0; i<30; i++){
        cout << i <<' ' <<  Euler(i)<< endl;
    }
}