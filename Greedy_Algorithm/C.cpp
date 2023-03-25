#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool myComparison(const int a,const int b){
    return a>b;
}
int index(vector<int>arr){
    int t = arr.size();
    for(t; t>0; t--){
        if(arr[t-1]>=t){
            return t;
        }
    }
    return t;
}
int main(){
    long long n, l;
    cin >> n>> l;
    vector<int> arr;
    for(long long i=0; i<n; i++){
        long long k;
        cin >> k;
        arr.push_back(k);
    }
    sort(arr.begin(), arr.end(), myComparison);
    int indexs = index(arr);
    if(indexs<n){
        int k = indexs-l+1;
        for(int i=indexs; i>=max(0, k); i--){
            arr[i]++;
        }
        sort(arr.begin(), arr.end(), myComparison);
        cout << index(arr);

    }
}