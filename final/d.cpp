#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int inf = 1000000;
        vector<vector<pair<int, int> > >arr(n);
        vector<int> minus;
        for(int i=0; i<m; i++){
            int q, w, e;
            cin >> q >> w >> e;
            arr[q-1].push_back(make_pair(w-1,e));
        }
        for(int i=0; i<n; i++){
            int l;
            cin >> l;
            minus.push_back(l);
        }
        int a, b;
        cin >> a >> b;
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
            for(int k=0; k<arr[v].size(); k++){
                if(arr[v][k].second>minus[arr[v][k].first]){
                    if(d[v] + arr[v][k].second- minus[arr[v][k].first]<d[arr[v][k].first]){
                        d[arr[v][k].first]=d[v]+arr[v][k].second - minus[arr[v][k].first];
                    }
                }
                else{
                    if(d[v] + arr[v][k].second<d[arr[v][k].first]){
                        d[arr[v][k].first]=d[v]+arr[v][k].second;
                    }
                }
            } 
        }
        if(d[b-1]>=inf){
            cout << -1<<endl;
        }
        else{
            cout << d[b-1]*10<<endl;
        }
    }

}