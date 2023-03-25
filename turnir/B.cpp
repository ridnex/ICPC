#include <iostream>
using namespace std;
int main(){
    long long n, m, s;
    cin >> n >>  m >> s;
    for(long int i=min(n, m); i>0; i--){
        int k = (n/i)*(m/i);
        if(k>=s){
            float j =(min(n, m)/i);
            float ans = min(n, m)/j;
            cout << ans;
            break;

        }
    }
}