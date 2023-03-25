#include <iostream>
#include <string>
using namespace std;
int main(){
    int n, a, b, cnt=0;
    cin >> n >> a >> b;
    int k =a+b;
    string str;
    cin >> str;
    for(int i=0; i<n; i++){
        if(str[i]=='.'){
            if(a<=0 and b<=0){
                break;
            }
            else if(i==0 ){
                cnt++;
                if(a>b){
                    str[i]='A';
                    a--;
                }
                else{
                    str[i]='B';
                    b--;
                }
            }
            else if(a<=0){
                if(str[i-1]!='B'){
                    cnt++;
                    str[i]='B';
                    b--; 
                }
            }
            else if(b<=0){
                if(str[i-1]!='A'){
                    cnt++;
                    str[i]='A';
                    a--; 
                }
            }
            else{
                if(str[i-1]=='*'){
                    cnt++;
                    if(a>b){
                        str[i]='A';
                        a--;
                    }
                    else{
                        str[i]='B';
                        b--;
                    }
                }
                else if(str[i-1]!='A'){
                    cnt++;
                    str[i]='A';
                    a--; 
                }
                else if(str[i-1]!='B'){
                    cnt++;
                    str[i]='B';
                    b--; 
                }
            }
        }


    }
    if(cnt>k){
        cout << k;
    }
    else{
        cout << cnt;
    }
}