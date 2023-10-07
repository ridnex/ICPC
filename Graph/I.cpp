#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool flag = false;
void dfs(int v, int k, vector<vector<int> >arr, vector<int>&was){
    was[v]=k%2;
    for(int i=0; i<arr[v].size(); i++){
        if(was[arr[v][i]]==-1){
            dfs(arr[v][i], k+1, arr, was);
            
        }
        else if(was[arr[v][i]]==was[v]){
            flag = true;
            return;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> >arr(n);
    vector<int>was(n, -1);
    while(m--){
        int a, b;
        cin >> a >> b;
        arr[a-1].push_back(b-1);
        arr[b-1].push_back(a-1);
    }
    for(int i=0; i<n; i++){
        if(was[i]==-1){
            dfs(i, 0, arr, was);
        }
        if(flag){
            cout << "NO";
            return 0;
        }
    }
    
    cout << "YES";
    
}
