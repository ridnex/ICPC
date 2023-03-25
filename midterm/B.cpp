#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string output;
    for(int i=0; i<n; i++){
        long long a, b;
        cin >> a >> b;
        if(a%(b+1)==0){
            output+="2";
        }
        else{
            output+="1";
        }
    }
    cout << output;
}