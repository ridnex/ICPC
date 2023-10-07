#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> >arr;
vector<int> dist;


void bfs(int start, vector<int>&was, ){
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