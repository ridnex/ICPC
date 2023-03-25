#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    int cnt=0;
    string a, b;
    cin >> a >> b;
    bool cond = false;
    if(n==1 and a!=b){
        cout << 1;
    }
    else{
    
        for(int i=0; i<n; i++){
            if(i==n-1 and (a[i]!=b[i])){
                cnt++;
            }
           
            else if(a[i]!=b[i]){
                cond =true;
            }
            else if(cond ==true and a[i]==b[i]){
                cnt++;
                cond = false;
            }
            
            
        }
        cout << cnt;
    }
}