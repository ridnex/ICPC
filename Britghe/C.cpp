#include <iostream>
#include <vector>
using namespace std;
vector<int> tp;
vector<vector<int> >arr(100001);
vector<vector<int> >r_arr(100001);
vector<int>was(100001, 0);
void dfs(int v){
    was[v]=1;
    for(int i=0; i<arr[v].size(); i++){
        if(!was[arr[v][i]]){
            dfs(arr[v][i]);
        }
    }
    tp.push_back(v);
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
    dfs(0);
    if(!was[n-1]){
        cout << "IMPOSSIBLE";
    }
    else{
        vector<int>len(n, 0);
        vector<int>parents(n, -2);
        vector<int>ans;

        len[0] = 1;
        parents[0]=-1;
        
        for(int i=tp.size()-1; i>=0; i--){
            for(int j=0; j<r_arr[tp[i]].size(); j++){
                if(len[tp[i]]<len[r_arr[tp[i]][j]]+1 and len[r_arr[tp[i]][j]]){
                    len[tp[i]]=len[r_arr[tp[i]][j]]+1;
                    parents[tp[i]] = r_arr[tp[i]][j];
                }
            }
        }
        cout << len[n-1]<<endl;

        int k = parents[n-1];
        ans.push_back(n-1);
        while(parents[k]!=-1){
            ans.push_back(k);
            k = parents[k];
        }
        ans.push_back(0);
        for(int i=ans.size()-1; i>=0; i--){
            cout << ans[i]+1<<" ";
        }
    }
}
    
