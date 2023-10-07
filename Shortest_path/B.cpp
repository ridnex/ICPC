#include <iostream>
#include <vector>
using namespace std;
int main(){
    freopen("sumdist.in", "r", stdin);
    freopen("sumdist.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int arr[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                arr[i][j]=0;
            }
            else{   
                arr[i][j]= 1000005;
            }
        }
    }
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        arr[a-1][b-1]= 1;
        arr[b-1][a-1]= 1;
    }
    
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                arr[i][j]=min(arr[i][j], arr[i][k]+arr[k][j]);
            }
        }
    }
    long long cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            cnt += arr[i][j];
        }
    }
    cout << cnt;
}