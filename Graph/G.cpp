#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, vector< vector<int> > v, vector<int>&was){
    was[n]=1;
    for(int i=0; i<v[n].size(); i++){
        if(!was[v[n][i]]){
            cout << n+1 <<" "<< v[n][i]+1<<endl;
            dfs(v[n][i], v, was);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> >v;
    vector<int>was;
    for(int i=0; i<n; i++){
        vector<int>a;
        v.push_back(a);
        was.push_back(0);
    }

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    dfs(0, v, was);
}