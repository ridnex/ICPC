#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    freopen("dijkstra.in", "r", stdin);
    freopen("dijkstra.out", "w", stdout);
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
        for(int k=0; k<n; k++){
            if(arr[v][k]!=-1 and v!=k){
                if(d[v] + arr[v][k]<d[k]){
                    d[k]=d[v] + arr[v][k];
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
