#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
int main(){

    int n, m;
    cin >> n >> m;
    int inf = -1;
    vector<vector<pair<int, double> > >arr(n);
    for(int i=0; i<m; i++){
        int q, w;
        double e;
        cin >> q >> w >> e;
        arr[q-1].push_back(make_pair(w-1,e/100));
        arr[w-1].push_back(make_pair(q-1,e/100));
    }

    vector<double>d(n, inf);
    d[0]=1;
    vector<int>was(n, 0);
    for(int i=0; i<n; i++){
        int v = -1;
        for(int j=0; j<n; j++){
            if(!was[j] and (v==-1 or d[j]>d[v])){
                v = j;
            }
        }
        if(d[v]==inf){
            break;
        }
        was[v] = 1 ;
        for(int k=0; k<arr[v].size(); k++){
            if(d[v] * arr[v][k].second>d[arr[v][k].first]){
                d[arr[v][k].first]=d[v]*arr[v][k].second;
            }
        } 
    }
    double ans = d[n-1]*100;
    
    cout <<setprecision (6) << fixed << ans<<" percent";
}
