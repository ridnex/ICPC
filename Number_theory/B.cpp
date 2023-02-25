#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n;i++){
        long long m, h=0, a;
        cin >> m;
        if(m ==1){
            cout <<"IMPOSSIBLE"<<endl;
        }
        else{
            for(int k=2; k<sqrt(m*2)+1; k++){
                if((m-k*(k-1)/2)%k==0){
                    a = (m-k*(k-1)/2)/k;
                    h = k;
                    break;
                }
            }
            
            if(h==0){
                cout <<"IMPOSSIBLE"<<endl;
            }
            else{
                cout<<m<<" = ";
                for(int j=a; j<a+h; j++){
                    if(j==a+h-1){
                    cout<<j;
                    cout << endl; 
                    }
                    else{
                        cout<<j<<" + ";
                    }
                    
                }
            }
        }

    }

}