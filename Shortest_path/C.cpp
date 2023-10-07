#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> >arr(1000001);
vector<int> was(100001, 0);

int main(){
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
    long long inf = -10000000;
    int n, m;
    cin >> n >> m;
    int carr[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            carr[i][j] = inf;
        }
    }
    int cnt = 0;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(carr[a-1][b-1]==inf){
            carr[a-1][b-1] = c;
            cnt++;
        }
        else{
            carr[a-1][b-1] = max(carr[a-1][b-1], c);
        }
    }
    vector<vector<int> >arr(cnt);
    int k=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(carr[i][j]!=inf){
                arr[k].push_back(i);
                arr[k].push_back(j);
                arr[k].push_back(carr[i][j]);
                k++;                
            }
        }
    }
    vector<long long>d(n, inf);
    d[0]=0;
    int x;
    for(int i=0; i<n; i++){
        x = -1;
        for(int j=0; j<arr.size(); j++){
            if(d[arr[j][0]]>inf){
                if(d[arr[j][1]]<d[arr[j][0]]+arr[j][2]){
                    d[arr[j][1]] = min(-inf, d[arr[j][0]]+arr[j][2]);
                    x = arr[j][1];
                }
            }
        }
    }
    if(d[n-1]==inf){
        cout << ":(";
    }
    else{
        if(x==-1){
            cout << d[n-1];
        }
        else{
            cout << ":)";
        }
    }
}