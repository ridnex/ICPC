#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> >arr;
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> >arr;
void bfs(int k, vector<int>&was, vector<int>&dist, int end){
    queue<int> q;
    dist[k]=0;
    was[k]=1;
    q.push(k);
    while(!q.empty()){
        bool cond = false;
        int u = q.front();
        q.pop();
        for(int i=0; i<arr[u].size(); i++){
            if(!was[arr[u][i]]){
                was[arr[u][i]]=1;
                dist[arr[u][i]]=dist[u]+1;
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
    int n;
    cin >> n;
    vector<int> was(n, 0);
    vector<int> dist(n, -1);

    for(int i=0; i<n; i++){
        vector<int> barr;
        for(int j=0; j<n; j++){
            
            int l;
            cin >> l;
            if(l==1){
                barr.push_back(j);
            }
        }
        arr.push_back(barr);
        barr.clear();
    }
    int start, end;
    cin >> start >> end;

    bfs(start-1, was, dist, end-1);

    cout << dist[end-1];

}
int main(){
    int n;
    cin >> n;
    vector<int> was(n, 0);
    vector<int> dist(n, -1);

    for(int i=0; i<n; i++){
        vector<int> barr;
        for(int j=0; j<n; j++){
            
            int l;
            cin >> l;
            if(l==1){
                barr.push_back(j);
            }
        }
        arr.push_back(barr);
        barr.clear();
    }
    int start, end;
    cin >> start >> end;

    bfs(start-1, was, dist, end-1);

    cout << dist[end-1];

}