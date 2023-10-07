#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> >arr(100001);
vector<pair<int, int> >output;
vector<int>tin(100001);
vector<int>fup(100001);

int timer;

bool myComparison(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}

void dfs(int v, vector<int>&was, int p=-1 ){
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
            dfs(to, was, v);
            fup[v] = min(fup[v], fup[to]);
            if(fup[to]>tin[v]){
                if(to<v){
                    output.push_back(make_pair(to, v));
                }
                else{
                    output.push_back(make_pair(v, to));
                }       
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n, cases = 1;
    cin >> n;
    while(n--){
        timer = 0;
        int m;
        cin >> m;
        int num = m;
        vector<int>was(m, 0);
        while(num--){
            int l, k;
            char q,w;
            cin >> k >> q>>l>>w;

            while(l--){
                int qw;
                cin >> qw;
                arr[k].push_back(qw);
            }
        }
        for(int i=0; i<m; i++){
            if(!was[i]){
                dfs(i, was);
            }
        }
        cout <<"Case "<<cases<<":"<<endl;
        cout <<output.size()<<" critical links"<<endl;
        sort(output.begin(), output.end(), myComparison);
        for(int i=0; i<output.size(); i++){
            cout << output[i].first<<" - "<<output[i].second<<endl;
        }
        output.clear();
        for(int i=0; i<m; i++){
            arr[i].clear();
            was[i]=0;
            tin[i]=0;
            fup[i]=0;
        }
        cases++; 
    }
}