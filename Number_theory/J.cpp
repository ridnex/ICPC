#include <iostream>
using namespace std;
string binary(long long n){
    
    if (n == 0)
        return "S";
    else if(n==1){
        return "SX";
    }
    else{
        return (binary(n / 2))+binary(n % 2) ;
    }
}
int main(){
    long long n;
    cin >> n;
    string str = binary(n);
    str.erase(0, 2); 
    cout << str;
}