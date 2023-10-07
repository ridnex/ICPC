#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(int start, vector<int>&was, vector<int>&dist, vector<int> arr[], vector<int>&parent, int end){
    queue<int> q;
    was[start] = 1;
    dist[start]= 0;
    parent[start] = -1;
    q.push(start);
    while(!q.empty()){
        bool cond = false;
        int u = q.front();
        q.pop();
        for(int i=0; i<arr[u].size(); i++){
            if(!was[arr[u][i]]){
                was[arr[u][i]]=1;
                dist[arr[u][i]]=dist[u]+1;
                parent[arr[u][i]] = u;
                q.push(arr[u][i]);
                if(arr[u][i]==end){
                    while(!q.empty()){
                        q.pop();
                    }
                    cond = true;
                }
                
            }
            if(cond){
                break;
            }
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr[n];
    vector<int>was(n, 0);
    vector<int>dist(n, -1);
    vector<int > parent(n);
    int start, end;
    cin >> start >> end;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        arr[a-1].push_back(b-1);
        arr[b-1].push_back(a-1);
    }
    
    bfs(start-1, was, dist, arr, parent, end-1);
    if(dist[end-1]==-1){
        cout << -1;
    }
    else{
        cout << dist[end-1]<<endl;
        vector<int> path;
        int last = end-1;
        path.push_back(last);

        while(parent[last]!=-1){
            path.push_back(parent[last]);
            last = parent[last];
        }
        for(int i=path.size()-1; i>=0; i--){
            cout << path[i]+1<<" ";
        }
        
    }
}