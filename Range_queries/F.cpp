#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    vector<vector<int> >arr;
    vector<int> ar;
    int x;
    cin >> x;
    ar.push_back(x);
    for(int i=1; i<n; i++){
        int x;
        cin >> x;
        if(x!=ar[-1]){
            arr.push_back(ar);
            ar.clear();
        }
        ar.push_back(x);
        if(i==n-1){
            arr.push_back(ar);
        }
    }
    for(int i=0; i<q; i++){
        int l, r;
        cin >> l >> r;
        
    }
}