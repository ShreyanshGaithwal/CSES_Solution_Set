
#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
    string s1;
    string s2;
    cin >> s1 >> s2;
    int n , m;
    n = s1.size();
    m = s2.size();

    vector<vector<int>> dp(n+1 , vector<int>(m+1 ,0 ) );
    for(int i = 1 ; i< n+1; i++) dp[i][0] = i;
    for (int j = 1; j < m+1 ; j++) dp[0][j] = j;

    for (int i = 1; i < n+1; i++){
        for (int j = 1;j < m+1; j++){
            if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1+ min({dp[i][j-1] , dp[i-1][j] , dp[i-1][j-1]});

        }
    }
    cout << dp[n][m]<<endl;
    */
    // space optimization
    
    string s1;
    string s2;
    cin >> s1 >> s2;
    int n , m;
    n = s1.size();
    m = s2.size();

    vector<int> next_arr(m+1 , 0);
    for (int i = 0; i <= m; i++) next_arr[i] = i;
     

    for (int i = 1; i < n+1; i++){
        vector<int> curr_arr(m+1 , 0);
        curr_arr[0] = i;
        for (int j = 1;j < m+1; j++){
            if (s1[i-1] == s2[j-1]) curr_arr[j] = next_arr[j-1];
            else curr_arr[j] = 1+ min({curr_arr[j-1] , next_arr[j] , next_arr[j-1]});

        }
        next_arr = curr_arr;
    }
    cout << next_arr[m]<<endl;
    return 0;
}