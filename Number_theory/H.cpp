#include <iostream>
#include <cmath>
using namespace std;
long long gcd(long long a, long long b){
    if(a==0){
        return b;
    }
    else if(b==0){
        return a;
    }
    if(a<b){
        return gcd(a, b%a);
    }
    else{
        return gcd(b, a%b);
    }
}
pair <long long, long long> gcd_xy(long long a, long long b){
    
    if(a == 0){
        return make_pair(0, 1);
    }
    long long x1, y1;
    x1 = gcd_xy(b%a, a).first;
    y1 = gcd_xy(b%a, a).second;
    return make_pair(y1-floor(b/a)*x1, x1);   
}   


int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        long long a, b;
        cin >> a >> b;
        if(gcd(a, b)!=1){
            cout << "No Solution"<<endl;
        }
        else{
            long long x0, y0;
            pair<long long, long long>p1;
            
            p1 = gcd_xy(a, b);
            
            
            x0 = p1.first;
            y0 = p1.second;
            long long k;
            if(x0>=0){
                float xx = x0;
                k = -1*floor(xx/b);
            }
            else{
                float xx = x0;
                k = -1*floor(xx/b);
            }
            cout << x0+k*b<<" "<<y0-k*a<<endl;
            
            
        }
    }
}