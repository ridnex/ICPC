#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool myComparison(const pair<int,int> &a,const pair<int,int> &b){
    return a.second<b.second;
}
int main(){
    int n;
    cin >> n;
    vector<pair<int , int> >arr(n+1, make_pair(100000, -100));
    for(int i=0; i<n; i++){
        int l;
        cin >> l;
        arr[l].first = min(arr[l].first, i);
        arr[l].second = max(arr[l].second, i);
    }
    vector<pair<int , int> >barr;
    for(int i=0; i<n+1; i++){
        if(arr[i].first != 100000){
            barr.push_back(arr[i]);
        }
    }
    sort(barr.begin(), barr.end(), myComparison);
    int cnt=1, k;
    k = barr[0].second;

    for(int i=1; i<barr.size(); i++){
        if(barr[i].first>k){
            cnt++;
            k = barr[i].second;
        }
    }

    cout << barr.size()-cnt;

}