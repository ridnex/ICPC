#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    long long cnt=0;
    cin >> n;
    priority_queue<long long,vector<long long>,greater<long long> >arr;
    for(long long i=0; i<n; i++){
        long long l;
        cin >> l;
        arr.push(l);
    }
    while(arr.size()!=1){
        long long v = arr.top();
        arr.pop();
        v+=arr.top();
        arr.pop();
        cnt+=v;
        arr.push(v);

        
    }
    cout << cnt;


}