#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    // freopen("dijkstra.in", "r", stdin);
    // freopen("dijkstra.out", "w", stdout);
    priority_queue<pair<int, int>,vector<pair<int, int> >,greater<pair<int, int> > >pq;
    int n, a, b;
    cin >> n >> a >> b;
    int inf = 1000000;
    int arr[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    vector<int>d(n, inf);
    pair<int, int>p1;
    d[a-1]=0;
    pq.push(make_pair(0, a-1));
    vector<int>was(n, 0);
    while(!pq.empty()){
        int distance, v;
        p1 = pq.top();
        distance = p1.first;
        v = p1.second;
        pq.pop();
        if(distance > d[v]){
            continue;
        }
        for(int i=0; i<n; i++){
            
            if(v!=i and arr[v][i]!=-1){
                if(distance + arr[v][i]<d[i]){
                    d[i]=distance + arr[v][i];
                    pq.push(make_pair(distance + arr[v][i], d[i]));
                }
            }
        }
        
    }
    if(d[b-1]==inf){
        cout << -1;
        return 0;
    }
    cout << d[b-1];
}
