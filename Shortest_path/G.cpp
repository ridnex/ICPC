#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    freopen("distance.in", "r", stdin);
    freopen("distance.out", "w", stdout);
    int n, m,  a, b;
    cin >> n >> m>> a >> b;
    int inf = 1000000;
    vector<vector<pair<int, int> > >arr(n);
    for(int i=0; i<m; i++){
        int q, w, e;
        cin >> q >> w >> e;
        arr[q-1].push_back(make_pair(w-1,e));
        arr[w-1].push_back(make_pair(q-1,e));
    }
    vector<int>d(n, inf), parent(n);
    d[a-1]=0;
    vector<int>was(n, 0);
    for(int i=0; i<n; i++){
        int v = -1;
        for(int j=0; j<n; j++){
            if(!was[j] and (v==-1 or d[j]<d[v])){
                v = j;
            }
        }
        if(d[v]==inf){
            break;
        }
        was[v] = 1 ;
        for(int k=0; k<arr[v].size(); k++){
            if(d[v] + arr[v][k].second<d[arr[v][k].first]){
                d[arr[v][k].first]=d[v]+arr[v][k].second;
                parent[arr[v][k].first] = v;
            }
        } 
    }
    if(d[b-1]==inf){
        cout << -1;
        return 0;
    }
    vector<int>path;
    cout << d[b-1]<<endl;
    for(int i=b-1; i!=a-1; i=parent[i]){
        path.push_back(i);
    }
    path.push_back(a-1);
    reverse(path.begin(), path.end());
    for(int i=0; i<path.size(); i++){
        cout << path[i]+1<<" ";
    }

}