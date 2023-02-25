#include <iostream>
using namespace std;
long long binpow(long long a, long long n, long long c){
    if(n==0){
        return 1;
    }
    if(n==1){
        return a%c;
    }
    long long x = binpow(a%c, n/2, c)%c;
    if(n%2==0){
        return x*x;
    }
    else{
        return (a%c)*x*x;
    }
}
int main(){
    long long a, b, c;
    while (cin >> a >> b>> c) {
        
        cout << binpow(a, b, c)%c<<endl;
        
    }

}