#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long n;
    cin >> n;
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
        cout << cnt <<endl;
        cin >> n;
        
    }
}