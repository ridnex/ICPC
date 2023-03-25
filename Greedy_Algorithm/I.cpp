#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool myComparison(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first-a.second==b.first-b.second){
        a.first<b.first;
    }
    return a.first-a.second<b.first-b.second;
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int k, p;
        long long cnt=0;
        cin >> k >> p;
        vector<int>arr;
        vector<pair<int , int> >barr;
        for(int j=0; j<k; j++){
            int l;cin >> l;
            arr.push_back(l);
        }
        for(int j=0; j<k; j++){
            int l;cin >> l;
            barr.push_back(make_pair(arr[j], l));
        }
        sort(barr.begin(), barr.end(), myComparison);
        
        for(int i=0; i<barr.size(); i++){
            if(p >= barr[i].first){
                long long q  = p - barr[i].first + (barr[i].first-barr[i].second);
                p = q%(barr[i].first-barr[i].second);
                cnt+=(q-p)/(barr[i].first-barr[i].second);
                p+=barr[i].second;
            }
            if(p==0){
                break;
            }
        }
        cout << cnt<<endl;
    }
}