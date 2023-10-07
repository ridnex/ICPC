#include <iostream>
using namespace std;
int main(){
    // freopen("floyd.in", "r", stdin);
    // freopen("floyd.out", "w", stdout);
    int n;
    cin >> n;
    int arr[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j]==-1){
                arr[i][j]=-100000;
            }
        }
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[i][j]=max(arr[i][j], arr[i][k]+arr[k][j]);
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j]<<" ";
        }
        cout << endl;
    }
}