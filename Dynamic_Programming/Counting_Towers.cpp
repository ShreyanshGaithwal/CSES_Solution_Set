#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    vector<vector<int>> dp(1e6+1, vector<int>(2,0));
    const int MOD = 1e9 + 7;
    int mx = 1e6+1;
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 1 ; i < mx; i++){
        dp[i][0] = (4LL * dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][1] = (2LL * dp[i-1][1] + dp[i-1][0]) % MOD;
    }
    while (t--)
    {
        int n;
        cin >> n;
        cout << (dp[n-1][0] + dp[n-1][1]) % MOD << endl;
    }
    return 0;
}