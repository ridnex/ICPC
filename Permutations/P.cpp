#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    for(int i=2; i<2+m; i++){
        cout << i << " ";
    }
    cout << 1 << " ";
    for(int j=2+m; j<=n; j++){
        cout << j<< " ";
    } 
}