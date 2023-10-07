#include <iostream>
#include <vector>
using namespace std;

bool Cyclic(int v,  vector<vector<int> >arr, vector<int>&was){
    was[v]=1;
    for(int i=0; i<arr[v].size(); i++){
        if(was[arr[v][i]]==0){
            if(Cyclic(arr[v][i], arr, was)){
                return true;
            } 
        }
        else if(was[arr[v][i]]==1){
            return true;
        }
    }
    was[v]=2;
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int> >arr;
    vector<int> was(n, 0);
    for(int i=0; i<n; i++){
        vector<int>bar;
        for(int j=0; j<n; j++){
            int l;
            cin >> l;
            if(l){
                bar.push_back(j);
            }
        }
        arr.push_back(bar);
        bar.clear();
    }
    bool cond = false;
    for(int i=0; i<was.size(); i++){
        
        if(Cyclic(i, arr, was)){
            cond = true;
            break;
        }
        
    }
    if(cond){
        cout << 1;
    }
    else{
        cout << 0;
    }
}