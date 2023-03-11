#include <iostream>
#include <string>
using namespace std;
void gen(int n, char s[], int i){
    if(i==n){
        for(int j=0; j<n; j++){
            cout << s[j]<<" ";
        }
        cout << endl;
        return;
    }
    s[i]='0';
    gen(n, s, i+1);
    s[i]='1';
    if(i==0 or s[i-1]!='1'){
        gen(n, s, i+1);
    }


}
int main(){
    int n;
    cin >> n;
    char asd[n];
    gen(n, asd, 0);
}