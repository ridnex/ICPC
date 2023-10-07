#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> >arr(100001);
vector<int>was(100001, 0);
vector<int> tp;
int flag =0;

void dfs(int v){
    was[v]=1;
    for(int i=0; i<arr[v].size(); i++){
        if(was[arr[v][i]]==0){
            dfs(arr[v][i]);
            
        }
        else if(was[arr[v][i]]==1){
            flag = 1;
            return;
        }
    }
    was[v]=2;
    
    tp.push_back(v);
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        arr[a-1].push_back(b-1);
    }
    for(int i = 0; i <n; i++){
        if(was[i] == 0){
            dfs(i);
        }
    }
    if(flag){
        cout << -1;
        return 0;
    }
    else{
        for(int i=tp.size()-1; i>=0; i--){
            cout << tp[i]+1<<" ";
        }
    }
}