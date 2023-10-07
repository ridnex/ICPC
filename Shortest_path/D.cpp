#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> >adj(1000001);
vector<int> was(1000001);
long long inf = 10000000001;
struct edge{
    int a, b, c;
    edge(int a, int b, int c) : a(a), b(b), c(c) {};
};
// void dfs(int v){
//     was[v]=1;
//     for(int i=0; i<adj[v].size(); i++){
//         if(!was[adj[v][i]]){
//             dfs(adj[v][i]);
//         }
//     }
// }
int main(){
    // freopen("path.in", "r", stdin);
    // freopen("path.out", "w", stdout);
    int n, m, v;
    cin >> n >> m>> v;
    vector<edge>arr;
    vector<long long>d(n, inf);
    vector<int>parent(n, -1);
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back(edge(a-1, b-1, c));
        adj[a-1].push_back(b-1);
    }
    int x;
    d[v-1]=0;
    for(int i=0; i<n+1; i++){
        x = -1;
        for(int j=0; j<m; j++){
            if(d[arr[j].a]<inf){
                if(d[arr[j].b]>d[arr[j].a]+arr[j].c){
                    d[arr[j].b] = max(-inf, d[arr[j].a]+arr[j].c);
                    parent[arr[j].b] = arr[j].a;
                    x = arr[j].b;
                }
            }
        }
    }
    if(x==-1){
        for(int i=0; i<n; i++){
            if(d[i]>=inf){
                cout << '*'<<endl;
            }
            else{
                cout << d[i]<<endl;
            }
        }
    }
    else{
        vector<int> was2(n, 0);
        int cnt = 0;
        int y = x;
        while(y!=x or cnt==0){
            was2[x]=1;
            x=parent[x];
            cout << x <<" ";
            cnt++;
        }
        cout << endl;
        for(int i=0; i<n; i++){
            if(was2[i]==1){
                cout << "-"<<endl;
            }
            else if(d[i]>=inf){
                cout << '*'<<endl;
            }
            else{
                cout << d[i]<<endl;
            }
        }
    }
}