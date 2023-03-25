#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool myComparison(const pair<int,int> &a,const pair<int,int> &b){
    return a.second<b.second;
}
int main(){
    int n;
    cin >> n;
    vector<pair<int, int> >arr;
    for(int i=0; i<n; i++){
        int a, b, c, d, x,y;
        char q, w;
        cin >> a>>q>>b>>c>>q>>d;
        pair <int, int> p1 = make_pair(a*60+b, c*60+d);

        arr.push_back(p1);
    }
    int cnt =1, l;
    sort(arr.begin(), arr.end(), myComparison);
    pair <int, int> p2 = arr[0];
    l = p2.second;
    for(int i=1; i<n; i++){
        pair <int, int> p2 = arr[i];
        if(p2.first>=l){
            cnt++;
            l = p2.second;
        }  
    }
    cout << cnt;
}