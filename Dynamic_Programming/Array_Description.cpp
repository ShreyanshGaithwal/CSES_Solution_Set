#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int &a : arr) cin>> a;
 
    vector<vector<int>> dp( n+1 ,vector<int>(m+2 , 0));
 
    if (arr[0] == 0){
        for (int i = 0 ; i < m+1; i++){
            dp[0][i] = 1;
        }
    }else{
        dp[0][arr[0]] = 1;
    }
    const int MOD = 1e9 +7;
 
    for (int i = 1 ; i <n ; i++){
        if (arr[i] == 0){
            for(int j = 1 ; j <= m ; j++){
                dp[i][j] = dp[i-1][j];
                if (j-1 > 0) dp[i][j] = (dp[i-1][j-1] + dp[i][j]) % MOD;
                if (j+1 <= m) dp[i][j] = (dp[i-1][j+1] + dp[i][j]) % MOD;
            }
        }else{
            dp[i][arr[i]] = dp[i-1][arr[i]];
            if (arr[i]-1 >0) dp[i][arr[i]] = (dp[i-1][arr[i]-1] + dp[i][arr[i]]) % MOD;
            if (arr[i]+1 <=m ) dp[i][arr[i]] = (dp[i-1][arr[i]+1] + dp[i][arr[i]]) % MOD;
        }
    }
 
    int ans = 0;
    for (int i = 1 ; i < m+1;i++){
        ans = (ans+ dp[n-1][i])% MOD;   
 }
 
    cout << ans << endl;
 
 
   
 
    return 0;   
}