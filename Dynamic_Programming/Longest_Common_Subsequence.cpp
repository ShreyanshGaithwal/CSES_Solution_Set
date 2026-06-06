#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , m;
    cin >> n >> m;
    vector<int> arr1(n,0);
    vector<int> arr2(m, 0);
    for (int &a : arr1) cin >>a ;
    for (int &a : arr2) cin >> a;
    vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));
    
    for (int i = 1 ; i < n+1 ; i++){
        for (int j = 1; j < m+1 ; j++){
            if (arr1[i-1] == arr2[j-1]){
                dp[i][j] = 1+ dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    vector<int> ans (dp[n][m], 0);
    int idx = dp[n][m] -1;


    int i = n, j = m;
    while (i > 0 && j > 0){
        if (dp[i][j] != max(dp[i-1][j] , dp[i][j-1])){
            ans[idx--] = arr1[i-1];
            i--;
            j--;
        }else{
            if (dp[i-1][j] >= dp[i][j-1]){
                i--;
            }else j--;
        }
    }



    cout<< dp[n][m] << endl;

    for (int a : ans) cout << a <<  " ";
    cout << endl;
    return 0;
    
}
