#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    // freopen("stdin", "r", stdin);
    // freopen("stdout", "w", stdout);
    long long n, cnt=0;
    cin >> n;
    string s;
    cin >> s;
    for(long long i=0; i<n*9; i++){
        if(i%9==0 and s[i]!='B'){
            cnt++;
        }
        else if(i%9==1 and s[i]!='S'){
            cnt++;
        }
        else if(i%9==2 and s[i]!='U'){
            cnt++;
        }
        else if(i%9==3 and s[i]!='I'){
            cnt++;
        }
        else if(i%9==4 and s[i]!='R'){
            cnt++;
        }
        else if(i%9==5 and s[i]!='O'){
            cnt++;
        }
        else if(i%9==6 and s[i]!='P'){
            cnt++;
        }
        else if(i%9==7 and s[i]!='E'){
            cnt++;
        }
        else if(i%9==8 and s[i]!='N'){
            cnt++;
        }
    }

    cout << cnt;
}