#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int >arr;
    for(int i=0; i<n; i++){
        int l; cin >> l;
        if(i==0){
            arr.push_back(l);
        }
        else{
            bool cond=false;
            sort(arr.begin(), arr.end());
            if(l>arr[arr.size()-1]){
                cond=true;
                arr[arr.size()-1]=l;
            }
            else{
                for(int j=0; j<arr.size()-1;j++){
                    if(l>arr[j] and l<arr[j+1]){
                        arr[j]=l;
                        cond = true;
                        break;
                    }
                }
            }
            if(cond==false){
                arr.push_back(l);
            }
        }
    }
    cout << arr.size();
    
}
