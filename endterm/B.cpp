#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long>arr;
    long long stud;
    for(int i=0; i<2*n; i++){
        if(i==0){
            cin >> stud;
        }
        else{
            long long l;
            cin >> l;
            arr.push_back(l);
        }
    }
    sort(arr.begin(), arr.end());
    vector<long long>arr2 =arr;
    vector<long long>barr;
    vector<long long>carr;

    long long second_team = arr2[0] + stud;
    int most = 1;
    int last = 1;
    long long team = arr[arr.size()-1] + stud;
    arr.erase(arr.end()-1);
    arr2.erase(arr2.begin());
    while(!arr.empty()){
        if(arr[arr.size()-1]+arr[0]>team){
            barr.push_back(arr[arr.size()-1]+arr[arr.size()-2]);
            arr.erase(arr.end()-1);
            arr.erase(arr.end()-1);
        }
        else{
            barr.push_back(arr[arr.size()-1]+arr[0]);
            arr.erase(arr.begin());
            arr.erase(arr.end()-1);
        }
    }
    while(!arr2.empty()){
        if(arr2[0]+arr2[arr2.size()-1]<second_team){
            carr.push_back(arr2[0] + arr2[1]);
            arr2.erase(arr2.begin());
            arr2.erase(arr2.begin());
        }
        else{
            carr.push_back(arr2[0]+arr2[arr2.size()-1]);
            arr2.erase(arr2.begin());
            arr2.erase(arr2.end()-1);
        }
    }

    sort(barr.end(), barr.end());
    sort(carr.begin(), carr.end());
    for(int i=barr.size()-1; i>=0; i--){
        if(team>=barr[i]){
            break;
        }
        if(team<barr[i]){
            most++;
        }
    }
    for(int i=carr.size()-1; i>=0; i--){
        if(second_team>=carr[i]){
            break;
        }
        if(second_team<carr[i]){
            last++;
        }
    }
    cout << most <<" "<<last;

}