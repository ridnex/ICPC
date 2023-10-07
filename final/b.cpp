#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int>arr;
    vector<int>barr;
    for(int i=0; i<n; i++){
        int l;
        cin >> l;
        arr.push_back(l);
    }
    for(int i=0; i<m; i++){
        int l;
        cin >> l;
        barr.push_back(l);
    }
    int cnt=0;
    long long sum1=0;
    long long sum2 =0;
    int index1=0;
    int index2 = 0;
    while(index1!=n and index2!=m){
        while(sum1!=sum2 or sum1==0){
            if(sum1<=sum2){
                sum1 += arr[index1];
                index1++;
            }
            else{
                sum2 += barr[index2];
                index2++;
            }
        }
        sum1 =0;
        sum2=0;
        cnt++;
    }
    cout << cnt;


}