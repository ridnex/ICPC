#include <iostream>
#include <vector>
using namespace std;
vector<int> tp;
vector<int> ans(100001, -1);
vector<int> color(100001, -1);
vector<vector<int> >arr(100001);
vector<vector<int> >r_arr(100001);
void dfs(int v,vector<int>&was){
    was[v]=1;
    for(int i=0; i<arr[v].size(); i++){
        if(!was[arr[v][i]]){
            dfs(arr[v][i], was);
        }
    }
    tp.push_back(v);
}

void reverse_dfs(int v, int c){
    color[v]=c;
    ans[c] = v;
    for(int i=0; i<r_arr[v].size(); i++){
        if(color[r_arr[v][i]]==-1){
            reverse_dfs(r_arr[v][i],c);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        arr[a-1].push_back(b-1);
        r_arr[b-1].push_back(a-1);
    }
    vector<int> was(n, 0);
    for(int i=0; i<n; i++){
        if(!was[i]){
            dfs(i, was);
        }
    }
    int c=0;
    for(int i=tp.size()-1; i>=0; i--){
        if(color[tp[i]]==-1){
            reverse_dfs(tp[i], c++);
        }
    }
    vector<int>was2(c, 1);
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            if(color[i] != color[arr[i][j]]){
                was2[color[i]]=0;
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<was2.size(); i++){
        if(was2[i]){
            cnt++;
        }
    }
    cout << cnt<<endl;
    
    for(int i=0; i<was2.size(); i++){
        if(was2[i]){
            cout << ans[i]+1<<" ";
        }
    }
}
