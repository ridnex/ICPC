#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > arr(n);
    vector<pair<int, int> > barr(m);
    vector<int>was(100005);
    vector<int>was2(100005);
    for(int i=0; i<n; i++){
        int l;
        cin >> l;
        arr[i] = make_pair(l, i);
    }
    for(int j=0; j<m; j++){
        int l;
        cin >> l;
        barr[j]= make_pair(l, j);
    }
    int mini = 10000005, l=0;
    int a, b, c, d;
    sort(arr.begin(), arr.end());
    sort(barr.begin(), barr.end());
    bool cond = false;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(l; l<m; l++){
                    int p = barr[l].first-arr[i].first-arr[j].first-arr[k].first;
                    
                    if(p==1){
                        cout << arr[i].second+1<<" "<< arr[j].second+1<<" "<<arr[k].second+1<<" "<<barr[l].second+1;
                        return 0;
                    }
                    else if(p>0){
                        if(p<mini){
                            mini = p;
                            a = arr[i].second;
                            b = arr[j].second;;
                            c = arr[k].second;;
                            d = barr[l].second;;
                            cond = true;
                            
                        }
                        l--;
                        
                        break;
                    }

                }
            }
        }
    }
    if(cond){
        cout << a+1<<" "<<b+1<<" "<< c+1<<" "<<d+1;
    }
    else{
        cout << -1;
    }

}