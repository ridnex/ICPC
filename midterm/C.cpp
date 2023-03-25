#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int a, int b){
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
int main(){
    int a, b;
    cin >> a >> b;
    int k = gcd(a, b);
    vector<int>arr;
    for(int i=1; i*i<=k; i++){
        if(k%i==0){
            if(i*i==k){
                arr.push_back(i);
            }
            else{
                arr.push_back(i);
                arr.push_back(k/i);
            }
        }
    }
    sort(arr.begin(), arr.end());
    int n;
    cin >> n;
    for(int  i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        bool cond = false;
        for(int j=arr.size()-1; j>=0; j--){
            
            if(arr[j]<a){
                cout << -1 << endl;
                cond = true;
                break;


            }
            else if(arr[j]<=b and arr[j]>=a){
                cout<< arr[j]<< endl;
                cond = true;
                break;
            }
            
        }
        if(cond == false){
            cout << -1<<endl;
        }
    }
}