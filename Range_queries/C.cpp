#include <iostream>
#include <vector>
using namespace std;
int arr[100001];
int t[400004][2];
void build(int v, int l, int r){
    if(l == r){
        t[v][0]=arr[l];
        t[v][1]=arr[l];
    }
    else{
        int m = (l+r)/2;
        build(2*v, l, m);
        build(2*v+1, m+1, r);
        t[v][0]=max(t[v*2][0], t[2*v+1][0]);
        t[v][1]=min(t[v*2][1], t[2*v+1][1]);
    }
}
pair<int, int>  get(int v, int l, int r, int L, int R){
    if(R<l or L>r){
        pair<int, int> p1= make_pair(-100009, 100009);
        return p1;
    }
    if(L<=l and r<=R){
        pair<int, int> p2= make_pair(t[v][0], t[v][1]);
        return p2;

    }
    int m = (l+r)/2;
    pair<int, int> p3;
    pair<int, int> p4;
    p3 = get(2*v, l, m, L, R );
    p4 = get(2*v+1, m+1, r, L, R);
    return make_pair(max(p3.first, p4.first), min(p3.second, p4.second));
}
int get_max(int v, int l, int r, int L, int R){
    if(R<l or L>r){
        return -100009;
    }
    if(L<=l and r<=R){
        return t[v][0];
    }
    int m = (l+r)/2;
    return max(get_max(2*v, l, m, L, R ),get_max(2*v+1, m+1, r, L, R));
    
}
int get_min(int v, int l, int r, int L, int R){
    if(R<l or L>r){
        return 1000009;
    }
    if(L<=l and r<=R){
        return t[v][1];
    }
    int m = (l+r)/2;
    return min(get_min(2*v, l, m, L, R ),get_min(2*v+1, m+1, r, L, R));
    
}
void update(int v, int l, int r, int i, int x){
    if(l==r){
        arr[l]=x;
        t[v][0]=x;
        t[v][1]=x;
    }
    else{
        int m = (l+r)/2;
        if(i<=m){
            update(2*v, l, m, i, x);
        }
        else{
            update(2*v+1, m+1, r, i, x);
        }
        t[v][0]= max(t[2*v][0],t[2*v+1][0]);
        t[v][1]= min(t[2*v][1],t[2*v+1][1]);
    }
}
int main(){
    // freopen("rvq.in", "r", stdin);
    // freopen("rvq.out", "w", stdout);
    int n, m;
    cin >>m;
    n=100001;
    for(int i=0; i<=n; i++){
        arr[i]=((i%12345)*(i%12345))%12345+(((i%23456)*(i%23456)%23456)*(i%23456))%23456;
    }
    build(1, 1, n);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        if(a<0){
            update(1, 1, n, -1*(a), b);
        }
        else{
            // cout << get_max(1, 1, n, a, b) - get_min(1, 1, n, a, b)<<endl;
            pair <int, int> p5 = get(1, 1, n, a, b);
            cout << p5.first - p5.second << endl;
        }
    }
}