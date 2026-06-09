#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> dp(n+1 , vector<int>(m+1 , 1e9));

    for (int x = 1 ; x <= n; x++){
        for (int y =1 ; y <=m ; y++){
            if (x == y){
                dp[x][y] = 0;
                continue;
            }

            int vertical = INT_MAX;
            for (int i = 1 ; i < y; i++){
                vertical = min(vertical , 1+ dp[x][i] + dp[x][y-i]);
            }
            int horizontal = INT_MAX;
            for (int i = 1 ; i < x; i++){
                horizontal = min(horizontal , 1+ dp[i][y]+ dp[x-i][y]);
            }
            dp[x][y] = min(horizontal , vertical);

        }
    }
    cout<<dp[n][m]<<endl;



    return 0;
    
}
