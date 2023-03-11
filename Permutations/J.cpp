#include <iostream>
#include <vector>
using namespace std;

void gen(vector<int>&v, int n){
    if(n==0){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    else if(n<0){
        return;
    }
    for(int i=1; i<=n; i++){
        if(v.size()==0){
            v.push_back(i);
            gen(v, n-i);
            v.pop_back();
        }
        else{
            if(v[v.size()-1]>=i){
                v.push_back(i);
                gen(v, n-i);
                v.pop_back();
            }
        }
    }

}
int main(){
    int n;
    cin >> n;
    vector<int>arr;
    gen(arr, n);
}