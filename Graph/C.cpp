#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n][n];
    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j]==1){
                cnt++;
            }
        }
        cout << cnt<< " ";
        for(int j=0; j<n; j++){
            if(arr[i][j]==1){
                cout << j+1<<" ";
            }
        }
        cout << endl;
    }
}