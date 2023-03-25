#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


string find_permutation(long long x, string str, long long facto[]){
    sort(str.begin(), str.end());
    string output = "";
    vector<int>arr;
    for(int i=1; i<=str.size(); i++){
        arr.push_back(i);
    }
    for(int i=str.size()-1; i>=0; i--){
        long long k = x/facto[i];
        output+= str[arr[k]-1];
        x = x%facto[i];
        arr.erase(arr.begin()+k);
    }
    return output;


}
int main(){
    long long facto[20];
    facto[0]=1;
    for(int i=1; i<20; i++){
        facto[i]=facto[i-1] * i;
    }
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string str;
        long long x;
        cin >> str;
        cin >> x;
        cout << find_permutation(x, str, facto)<<endl;
    }
}

