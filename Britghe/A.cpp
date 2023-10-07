#include <iostream>
#include <vector>
using namespace std;
vector<int> tp;
vector<int> comp;
vector<vector<int> >arr(20001);
vector<vector<int> >r_arr(20001);
void dfs(int v,vector<int>&was){
    was[v]=1;
    for(int i=0; i<arr[v].size(); i++){
        if(!was[arr[v][i]]){
            dfs(arr[v][i], was);
        }
    }
    tp.push_back(v);
}

void reverse_dfs(int v, vector<int>&was2){
    was2[v]=1;
    comp.push_back(v);
    for(int i=0; i<r_arr[v].size(); i++){
        if(!was2[r_arr[v][i]]){
            reverse_dfs(r_arr[v][i], was2);
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
    vector<int> was2(n, 0);
    int count[n];
    int cnt=0;
    int k=1;
    for(int i=tp.size()-1; i>=0; i--){
        if(!was2[tp[i]]){
            reverse_dfs(tp[i], was2);
            for(int j=0; j<comp.size(); j++){
                count[comp[j]]=k;
            }
            comp.clear();
            cnt++;
            k++;
        }
    }
    cout << cnt<<endl;
    
    for(int i=0; i<n; i++){
        cout << count[i]<<" ";
    }
}
