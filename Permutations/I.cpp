#include <iostream>
using namespace std;

void gen(string str, int l, int r){
    if(l==r and l==0){
        cout<<str<<endl;
    }
    else if(l>r){
        return;

    }
    if(l>0){
        gen(str+"(", l-1, r);
    }
    if(r>0){
        gen(str+")", l, r-1);
    }

}
int main(){
    int n;
    cin >> n;
    string str="";
    gen(str, n, n);
}