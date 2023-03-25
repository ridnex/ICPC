#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// int log_prime(long long m){
//     long long b;
//     b = floor(sqrt(m));
//     long long cnt = 0;
//     vector <long long> u(b+1, 0);
//     for(long long i=2; i<b+1; i++){
//         if(u[i]==0){
//             for(long long j=(i)*(i); j<b+1;j+=(i) ){
//                 u[j]=1;   
//             }
//             cnt += floor(log(m)/log(i))-1;

            
//         }   
//     }
//     return cnt;

// }
int main(){
    // int k;
    // cin >> k;
    cout << "lol"<<endl;
    char arr[10000002];
    fill(arr,arr+10000000,'0');
    vector<long long> barr;
    for(long long i=2; i<10000001; i++){
        if(arr[i]=='0'){
            for(long long j=(i)*(i); j<10000001;j+=(i) ){
                arr[j]='1';   
            }
            barr.push_back(i);
        }   
    }
    for(long long i=0; i<barr.size(); i++){
        cout << barr[i]<<" ";
    }

    // for(int l=0; l<k;l++){
    //     long long a, m;
    //     cin >> a >> m;
    //     cout<<log_prime(m)-log_prime(a-1)<<endl;
    // }
    
}