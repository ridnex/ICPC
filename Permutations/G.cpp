#include <vector>
#include <set>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
set<vector <int> > output;
void gen(vector<int>v, vector<int>arr,int p, int x){
    if(x == 0){
        output.insert(v);
    }
    else if (x<0){
        return;
    }
    else {
        for(int i = p+1; i < arr.size(); i++) {
            v.push_back(arr[i]);
            gen(v, arr, i, x-arr[i]);
            v.pop_back();
        }
    }
}

int main(){
    int n;
    int x, y;
    while(cin >> x >> y){
        output.clear();
        vector<int>arr;
        vector<int>barr;
        vector<int>v;
        for(int i=0; i<y; i++){
            int l;
            cin >> l;
            arr.push_back(l);
        }
        gen(v, arr, -1, x);
        cout << "Sums of " << x <<":"<< endl;
        if(output.size()==0){
            cout << "NONE"<<endl;
        }
        else{
            for(set<vector <int> >::reverse_iterator it= output.rbegin(); it!=output.rend(); it++){ 
                
                barr = *it;
                
                for(int i=0; i<barr.size(); i++){
                    if(i==barr.size()-1){
                        cout<<barr[i]<<endl;
                    }
                    else{
                        cout<<barr[i]<<"+";
                    }
                }

            }
        }
        
    }

}

