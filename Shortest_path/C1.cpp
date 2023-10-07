#include <iostream>
#include <vector>
using namespace std;
struct edge
{
    int a, b, c;
    edge(int a, int b, int c) : a(a), b(b), c(c) {};
};
vector<edge>arr;
vector<vector<int> >adj(1000001);
vector<int> was(100001, 0);
void dfs(int v){
    was[v]=1;
    for(int i=0; i<adj[v].size(); i++){
        if(!was[adj[v][i]]){
            dfs(adj[v][i]);
        }
    }

}

int main(){
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
    long long inf = -10000000;
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back(edge(a-1, b-1, c));
        adj[a-1].push_back(b-1);
    }
    vector<long long>d(n, inf);
    d[0]=0;
    int x;
    for(int i=0; i<n+1; i++){
        x = -1;
        for(int j=0; j<m; j++){
            if(d[arr[j].a]>inf){
                if(d[arr[j].b]<d[arr[j].a]+arr[j].c){
                    d[arr[j].b] = min(-inf, d[arr[j].a]+arr[j].c);
                    x = arr[j].b;
                }
            }
        }
    }
    if(x!=-1){
        dfs(x);
        if(was[n-1]){
            cout << ":)";
            return 0;
        }
    }
    if(d[n-1]<=inf){
        cout << ":(";
        return 0;
    }
    cout << d[n-1];
}