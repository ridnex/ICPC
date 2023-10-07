#include <iostream>
using namespace std;
int n; 
int arr[1001];
int t[40004];

void build(int v, int  l,int  r){
    if(l==r){
        t[v] = arr[l];
    }
    else{
        int m=(l+r)/2;
        build(2*v, l, m);
        build(2*v+1, m+1, r);
        t[v]=min(t[2*v],t[2*v+1]);
    }
}
int get(int v, int l, int r, int L, int R){
    if(R<l or L>r){
        return 1000000005;
    }
    if(L<=l and r<=R){
        return t[v];
    }
    int m=(l+r)/2;
    return min(get(2*v, l, m , L,  R ), get(2*v+1, m+1, r, L, R));
}
int main(){
    freopen("stupid_rmq.in", "r", stdin);
    freopen("stupid_rmq.out", "w", stdout);
    int n; 
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    build(1, 0, n-1);
    int k;
    cin >> k;
    for(int j=0; j<k; j++){
        int L, R;
        cin >> L >> R;
        cout <<get(1, 0, n-1, L-1, R-1)<<endl;
    }

}