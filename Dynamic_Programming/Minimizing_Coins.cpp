#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , x ;
    cin >> n >> x ;
    vector<int> coins(n) ;
    for (int i = 0 ; i< n ; i++) cin >> coins[i] ;
 
    vector<int> dp(x+1, x+1);
    dp[0] = 0;
 
    for(int i = 1; i < x+1 ; i++){
        for (int j : coins){
            if (j <= i){
                dp[i] = min(dp[i] , 1+ dp[i-j]) ;
            }
        }
    }
    if (dp[x] != x+1) cout << dp[x] << endl; 
    else cout << -1 << endl;
    return 0;   
}