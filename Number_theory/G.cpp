#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
vector<bool>arr(1000005, true);
vector <unsigned long long> barr;

void primes(){
    for (unsigned long long i = 2; i < 1000004; i++) {
        if(arr[i]){
            for(unsigned long long j = i * i; j < 1000004; j += i) {
                arr[j] = false; 
            }
            unsigned long long k = i * i;
            while(k<=1000000000005){
                barr.push_back(k);
                k*=i;
            }
            barr.push_back(k);
        }
    }
}


unsigned long long solving_low_hight(unsigned long long a, unsigned long long b){
    
    unsigned long long cnt2 = lower_bound(barr.begin(), barr.end(), a) - barr.begin();
    unsigned long long cnt1 = lower_bound(barr.begin(), barr.end(), b) - barr.begin();
    if(cnt2==cnt1){
        if(*lower_bound(barr.begin(), barr.end(), a) <= b && *lower_bound(barr.begin(), barr.end(), a) >= a){
            return 1;
        }
        return 0;
    }
    return cnt1-cnt2;

}


int main(){
    primes();
    sort(barr.begin(), barr.end());
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        unsigned long long a, b;
        cin >> a >> b;
        cout << solving_low_hight(a, b)<<endl;
    }
}