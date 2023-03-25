#include <iostream>
#include <vector>
using namespace std;
int bin(int x, vector<int>&arr){
    int left = 0, right = arr.size()-1, middle;
    while(left<=right){
        middle = (left+right)/2;
        if(x>arr[middle]){
            left =middle +1;
        }
        else{
            right = middle-1;
        }

    }
    return left;
}

int main(){
    int n; 
    while(cin >> n){
        vector<int>arr;
        for(int i=0; i<n; i++){
            int l;
            cin >> l;
            if(i==0){
                arr.push_back(l);
            }
            else if(arr[arr.size()-1]<l){
                arr.push_back(l);
            }
            else{
                arr[bin(l, arr)]=l;
            }
        }
        cout << arr.size()<<endl;
    }
}