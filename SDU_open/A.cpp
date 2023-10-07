#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    float m = n;
    int a, b, c;
    a = ceil(m/12);
    b = ceil(m/4)-a;
    c = ceil(m/2)-a-b;
    cout << a <<" "<< b << " "<<c;
}