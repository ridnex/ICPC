#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool myComparison(const pair<float, long long> &a,const pair<float, long long> &b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}
int main(){
    long long n; 

    while(cin >> n){
        
        vector<pair<float, long long> > arr;
        for(long long i=1; i<=n; i++){
            float t, s, l;
            cin >> t >> s;
            l = t/s;
            pair<float, long long> p1 = make_pair(l, i);
            arr.push_back(p1);
        }
        sort(arr.begin(), arr.end(), myComparison);
        
        for(long long i=0; i<arr.size(); i++){
            cout << arr[i].second<<" ";
        }
        cout << endl;
    }
}