#include <iostream>
using namespace std;
int arr[500001];
int t[2000001];
void build(int v, int l, int r){
    if(l == r){
        t[v]=arr[l];
    }
    else{
        int m = (l+r)/2;
        build(2*v, l, m);
        build(2*v+1, m+1, r);
        t[v]=t[v*2]+t[2*v+1];
    }
}
long long get(int v, int l, int r, int L, int R){
    if(R<l or L>r){
        return 0;
    }
    if(L<=l and r<=R){
        return t[v];
    }
    int m = (l+r)/2;
    return get(2*v, l, m, L, R )+get(2*v+1, m+1, r, L, R);
}
void update(int v, int l, int r, int i, int x){
    if(l==r){
        arr[l]=x;
        t[v]=x;
    }
    else{
        int m = (l+r)/2;
        if(i<=m){
            update(2*v, l, m, i, x);
        }
        else{
            update(2*v+1, m+1, r, i, x);
        }
        t[v]= t[2*v]+t[2*v+1];
    }
}
int main(){
    int n, m;
    cin >> n>>m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    build(1, 0, n-1);
    for(int i=0; i<m; i++){
        char p;
        int a, b;
        cin >> p >> a >> b;
        if(p=='='){
            update(1, 0, n-1, a-1, b);
        }
        else{
            cout << get(1, 0, n-1, a-1, b-1)<<endl;
        }

    }

}