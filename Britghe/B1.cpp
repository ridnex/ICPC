#include <iostream>
#include <vector>
using namespace std;
vector<int>tp;
vector<vector<int> >arr(100001);
vector<int>was(100001, 0);
vector<int>in_output(100001, 0);
vector<int>output;
int timer, tin[100001], fup[100001];
void dfs(int v, int p=-1){
    was[v]=1;
    tin[v] = fup[v] = timer++;
    for(int i=0; i<arr[v].size(); i++){
        int to = arr[v][i];
        if(to == p){
            continue;
        }
        if(was[to]){
            fup[v] = min(fup[v], tin[to]);
        }
        else{
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if(fup[to]>tin[v] and in_output[to]==0){
                output.push_back(to);
                in_output[to]=1;
            }
        }
    }
    tp.push_back(v);
}
int main(){
    timer = 0;
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        arr[a-1].push_back(b-1);
    }

    for(int i=0; i<n; i++){
        if(!was[i]){
            dfs(i);
        }
    }
    for(int i=0; i<tp.size(); i++){
        if(arr[tp[i]].size()==0 and in_output[tp[i]]==0){
            output.push_back(tp[i]);
            in_output[tp[i]]=1;
        }
    }
    if(output.size()==0){
        cout << 1<<endl;
        cout << tp[n-1]+1;
    }
    else{
        cout << output.size()<<endl;
        for(int i=0; i<output.size(); i++){
            cout << output[i]+1<<" ";
        }
    }
}