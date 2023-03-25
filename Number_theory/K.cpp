#include <iostream>
using namespace std;
unsigned long long  a, b, c;

unsigned long long bin_pow_sum(unsigned long long a, unsigned long long b) {
    if (b == 0){
        return 0;
    }
    if (b == 1){
        return a % c;
    }
    unsigned long long x;
    if (b % 2 == 0) {
        x = bin_pow_sum(a, b / 2) % c;
        return (x + x) % c;
    }
    
    x = bin_pow_sum(a, b / 2) % c;
    return (x + x + a) % c;
      
    
}

unsigned long long bin_pow_deg(unsigned long long a, unsigned long long b) {
    if(b == 0){
        return 0;
    }
    if(b == 1){
        return a % c;
    }
    unsigned long long x;
    if(b % 2 == 0) {
        x = bin_pow_deg(a % c, b / 2) % c;
        return bin_pow_sum(x, x) % c;
    }
    
    x = bin_pow_deg(a% c, b / 2) % c;
    return bin_pow_sum(bin_pow_sum(x, x) % c, a % c)%c;
    
    
}

int main() {
    while (cin >> a >> b >> c) {
        cout << bin_pow_deg(a, b) % c << endl;
    }
}