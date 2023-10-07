#include <iostream>
#include <vector>
using namespace std;
int k = 1e9 + 7;
vector<vector<int> >reverse_arr(100001);
vector <long long> dp(100001, -1);
int dfs(int v) {
    if (dp[v] != -1) {
        return dp[v] % k;
    }
    else {
        dp[v] = 0;
        for (int i=0; i<reverse_arr[v].size(); i++) {
            dp[v]+=dfs(reverse_arr[v][i])%k;
        }
        return dp[v]%k;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        reverse_arr[b-1].push_back(a-1);
    }
    dp[0] = 1;
    cout << dfs(n-1)%k;
}