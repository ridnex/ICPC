#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    long long n;
    cin >> n;
    long long stud;
    cin >> stud;
    vector<float> arr;
    for(int i=0; i<2*n-1; i++){
        long long l;
        cin >> l;
        arr.push_back(l);
    }
    sort(arr.begin(), arr.end());
    
    long long most = 1;
    long long last = 1;
    float team_1 = stud + arr[arr.size()-1];
    team_1 = team_1 / 2;
    float team_2 = stud + arr[0];
    team_2 = team_2 / 2;

    vector<float>arr2 =arr;
    vector<float>barr;
    vector<float>carr;
    arr2.erase(arr2.begin());
    arr.erase(arr.end()-1);

    for(int i=0; i<arr2.size(); i++){
        bool cond = false;
        for(int j=i+1; j<arr2.size(); j++){
            if((arr2[i]+arr2[j])/2>team_2){
                carr.push_back((arr2[i]+arr2[j])/2);
                arr2.erase(arr2.begin()+j);
                cond = true;
                break;
            }
        }
        if(!cond){
            carr.push_back((arr2[i]+arr2[i+1])/2);
            arr2.erase(arr2.begin()+i+1);
        }
    }
    reverse(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); i++){
        bool cond = false;
        for(int j=i+1; j<arr.size(); j++){
            if((arr[i]+arr[j])/2<team_1){
                barr.push_back((arr[i]+arr[j])/2);
                arr.erase(arr.begin()+j);
                cond = true;
                break;
            }
        }
        if(!cond){
            barr.push_back((arr[i]+arr[i+1])/2);
            arr.erase(arr.begin()+i+1);
        }
    }
    
    sort(barr.begin(), barr.end());
    sort(carr.begin(), carr.end());
    for(int i=barr.size()-1; i>=0; i--){
        if(team_1>=barr[i]){
            break;
        }
        if(team_1<barr[i]){
            most++;
        }
    }
    for(int i=carr.size()-1; i>=0; i--){
        if(team_2>=carr[i]){
            break;
        }
        if(team_2<carr[i]){
            last++;
        }
    }
    cout << most <<" "<<last;


}