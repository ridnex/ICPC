#include <bits/stdc++.h>
using namespace std;
int main(){

    bool arr[1000005];
    arr[1]=1;
    for(long long i=2; i<=1000000; i++){
        if(arr[i]){
            continue;
        }
        for(long long j=(i)*(i); j<=1000000;j+=(i) ){
            arr[j]=1;   
        }        
    }
    long long n;
    cin >> n;
    
    while(n--){
        long long a, b;
        cin >> a >> b;
        if(a<=1){
            a = 2;
        }
        long long output=0;
        for(long long i=2; i<=min(b, 1ll*1000000); i++){
            if(arr[i]){
                continue;
            }
            long long cnt1=0, cnt2=0;
            long long index_a = a-1, index_b=b;
            while(index_a>0){
                index_a/=i;
                cnt2++;
            }
            while(index_b>0){
                index_b/=i;
                cnt1++;
            }
            cnt1--;
            cnt2--;
            output+=cnt1-cnt2;
            if(a<=i and i<=b){
                output--;
            }
        }
        cout << output<<endl;

    }
    

}