#include <iostream>
#include <vector>
using namespace std;

int cnt;
void dfs(int x, int y, int a, int b, vector<vector<int> >arr, vector<vector<int> >&was){
    was[x][y]=1;
    cnt++;
    if(x+1 < b and arr[x+1][y]!='#' and was[x+1][y]==0){
        dfs(x+1, y, a, b, arr, was);
    }
    if(x-1 >= 0 and arr[x-1][y]!='#' and was[x-1][y]==0){
        dfs(x-1, y, a, b, arr, was);
    }
    if(y+1 < a and arr[x][y+1]!='#' and was[x][y+1]==0){
        dfs(x, y+1, a, b, arr, was);
    }
    if(y-1 >= 0 and arr[x][y-1]!='#' and was[x][y-1]==0){
        dfs(x, y-1, a, b, arr, was);
    }
    
}
int main(){
    int n;
    cin >> n;
    int k=1;
    while(n--){
        int a, b;
        cin >> a >> b;
        int x, y;
        vector<vector<int> >arr;
        vector<int>carr(a, 0);
        vector<vector<int> >was;
        for(int i=0; i<b; i++){
            vector<int> barr;
            was.push_back(carr);
            for(int j=0; j<a; j++){
                char l;
                cin >> l;
                barr.push_back(l);
                if(l=='@'){
                    x=i;
                    y=j;
                }
            }
            arr.push_back(barr);
            barr.clear();
        }
        cnt = 0;
        dfs(x, y,a, b, arr, was);
        cout << "Case "<<k<<": "<<cnt<<endl;
        k++;
        arr.clear();
        was.clear();
        carr.clear();
        
    }
}