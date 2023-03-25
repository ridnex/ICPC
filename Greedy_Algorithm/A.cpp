#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main(){
    int n, k, cnt = 0;
    cin >> n>> k;
    vector<int>arr;
    vector<int>barr;
    for(int i=0; i<n; i++){
        int l;
        cin >> l;
        arr.push_back(l);
    }
    sort(arr.begin(), arr.end());
    if(arr[arr.size()-1]>k){
        cout << "Impossible";
    }
    else{
        for(int i=0; i<arr.size(); i++){
            bool cond = false;
            for(int j=arr.size()-1; j>i; j--){
                if(arr[i]+arr[j]<=k){
                    arr.erase(arr.begin()+j);
                    cnt++;
                    cond = true;
                    break;
                }
            }
            if(cond == false){
                cnt+=arr.size()-i;
                break;
            }
            
        }
        cout << cnt;
    }

}