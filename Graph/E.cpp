#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n][n];
    vector<int>sources;
    vector<int>sinks;
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j]==1){
                cnt++;
            }
        }
        if(cnt==0){
            sources.push_back(i+1);
        }
    }
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(arr[j][i]==1){
                cnt++;
            }
        }
        if(cnt==0){
            sinks.push_back(i+1);
        }
    }
    cout <<sinks.size()<<" ";
    for(int i=0; i<sinks.size(); i++){
        cout << sinks[i]<<" ";
    }
   cout << endl<< sources.size()<<" ";
    for(int i=0; i<sources.size(); i++){
        cout << sources[i]<<" ";
    }
    
}