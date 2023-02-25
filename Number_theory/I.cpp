#include <iostream>
using namespace std;
long long binpow(long long a, long long n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return a;
    }
    long long x = binpow(a, n/2);
    if(n%2==0){
        return x*x;
    }
    else{
        return a*x*x;
    }
}
int main(){
    long long n, a;
    cin >> a >> n;
    cout << binpow(a, n);

}