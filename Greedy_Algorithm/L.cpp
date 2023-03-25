#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool myComparison(const pair<long long, long long> &a,const pair<long long, long long> &b){
    if(a.first-a.second==b.first-b.second){
        return a.first<b.first;
    }
    return a.first-a.second<b.first-b.second;
}
int main(){
    long long n;
    cin >> n;
    long long cnt = 0, damage = 0;
    vector<pair< long long, long long> > arr;
    for(long long i=0; i<n; i++){
        long long l, d;
        cin >> l>> d;
        arr.push_back(make_pair(l, d));
    }
    sort(arr.begin(), arr.end(), myComparison);
    pair<long long, long long>p1;
    for(long long i=0; i<n; i++){
        if(i==0){
            p1.first = arr[i].first;
            p1.second = arr[i].second;
            
            
        }
        else{
            if(p1.first<=arr[i].second and p1.second<arr[i].first){ 
                p1.first=arr[i].first;
                p1.second+=arr[i].second;

            }
            else if(p1.first<=arr[i].second and p1.second>=arr[i].first){
                p1.first=min(arr[i].first, p1.first);
                p1.second+=arr[i].second;
            }
            else if(p1.first>arr[i].second and p1.second>=arr[i].first){
                p1.second+=arr[i].second;
            }
            else{
                cout << "gg";
                return 0;
            }
        }
    }
    cout << p1.first;
}