#include <iostream>
#include <vector>
using namespace std;
int main(){
    int s, n;
    cin >>s >> n;
    vector<int> arr(10000, 0);
    arr[0]=1;

    
    for(int i=0; i<n; i++){
        int l;
        cin >> l;
        for(int j=s; j>=l; j--){
            
            if(arr[j-l]==1){
                arr[j]=1;
            }
        }
    }
    
    for(int k=s+1; k>=0; k--){
        if(arr[k]==1){
            cout << k;
            return 0;
        }
    }

}