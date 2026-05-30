#include <bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin >> n ;
    const int MOD  = 1e9 +7;
    vector<int> dp = {1};
 
    for(int i =  1; i <= n ; i++){
        int curr = 0;
        for (int d = 1 ; d <= 6 ; d++){
            if (i-d >= 0){
               curr = (curr + dp[d-1]) % MOD;
            }
        }
        dp.push_back(curr);
 
        if (dp.size() >= 7){
            dp.erase(dp.begin());
        }
    }
 
    cout << dp.back() << endl;
    return 0;
}