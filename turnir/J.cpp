#include <iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;
    for(long long i=0; i<n; i++){
        long long a, b, x;
        cin >> a>> b >>x;
        if(x>a){
            cout << x-b+1<<endl;
        }
        else{
            cout << a-b+2<<endl;
        }
    }
}