#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int log_prime(long long m){
    long long b;
    b = floor(sqrt(m));
    long long cnt = 0;
    vector <long long> u(b+1, 0);
    for(long long i=2; i<b+1; i++){
        if(u[i]==0){
            for(long long j=(i)*(i); j<b+1;j+=(i) ){
                u[j]=1;   
            }
            cnt += floor(log(m)/log(i))-1;

            
        }   
    }
    return cnt;

}
int main(){
    int k;
    cin >> k;
    for(int l=0; l<k;l++){
        long long a, m;
        cin >> a >> m;
        cout<<log_prime(m)-log_prime(a-1)<<endl;
    }
    
}