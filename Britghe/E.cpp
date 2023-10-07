#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> >arr(100001);
vector<int>tin(100001);
vector<int>fup(100001);
vector<int>was(100001, 0);
vector<int>vertice(100001, 0);
int timer;
void dfs(int v, int p=-1){
    was[v]=1;
    tin[v]=fup[v]= timer++;
    int child = 0;
    for(int i=0; i<arr[v].size(); i++){
        if(arr[v][i]==p){
            continue;
        }
        if(was[arr[v][i]]){
            fup[v]= min(fup[v], tin[arr[v][i]]);
        }
        else{
            dfs(arr[v][i], v);
            fup[v]= min(fup[v], fup[arr[v][i]]);
            if(fup[arr[v][i]]>= tin[v] and p!=-1){
                vertice[v]=1;
            }
            ++child;
        }
    }
    if(p == -1 and child >1){
        vertice[v]=1;
    }
}
int main(){
    int t;
    cin >> t;
    int k=1;
    while(t--){
        timer = 0;
        int n, m;
        cin >> n >> m;
        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;
            arr[a-1].push_back(b-1);
            arr[b-1].push_back(a-1);
        }
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            if(!was[i]){
                dfs(i);
            }
        }
        for(int i=0; i<n; i++){

            if(vertice[i]==1){
                cnt++;
            }
        }
        cout << "Case "<<k<<": "<<cnt<<endl;
        for(int i=0; i<n; i++){
            arr[i].clear();
            was[i]=0;
            tin[i]=0;
            fup[i]=0;
            vertice[i]=0;
        }
        k++;
    }
}