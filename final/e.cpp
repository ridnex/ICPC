#include <iostream>
#include <vector>
#include <map>
using namespace std;

map <string, int> map1;
int main() {
    int n; 
    cin >> n;
    vector <string> arr;
    for (int i=1; i<=n; i++) {
        string x, y; 
        cin >> x >> y;
        arr.push_back(x);
        map1[y] = i;
    }
    for(int i=0; i<arr.size(); i++) {
        cout << map1[arr[i]] << endl;
    }
}