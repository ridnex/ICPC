#include <iostream>
#include <vector>
using namespace std;
long long prime_arr(long long a, long long b){
    long long cnt = 0;
    // long long u[b+1];
    // for(int i=0; i<b+1;i++){
    //     u[i]=0;
        
    // }
    vector <long long> u(b+1, 0);
    for(long long i=2; i<b+1; i++){
        if(u[i]==0){
            for(long long j=(i)*(i); j<b+1;j+=(i) ){
                u[j]=1;
                
            }
            if(i>=a){
                cnt++;
            }

        }
        
    }
    
    return cnt;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long a, b;
    while (cin >> a >> b) {
        
        cout<<prime_arr(a, b)<<endl<<"\n";
        
    }
}