#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<char>>arr (n  ,vector<char>(n));
    for (int i = 0; i< n ; i++){
        for (int j = 0; j< n ; j++){
            cin>> arr[i][j];
        }
    }
 
 
    const int MOD = 1e9 +7;
    vector<int> next_arr(n+1 , 0);
    if (arr[0][0] != '*' || arr[n-1][n-1] != '*'){
        next_arr[1] = 1;
    }
    
 
 
    for(int i = 1 ; i <= n ; i++){
        vector<int> curr_arr(n+1 , 0);
        for (int j = 1 ; j <= n; j++){
            if (arr[i-1][j-1] != '*'){
                curr_arr[j] = (next_arr[j] + curr_arr[j-1]) % MOD;
            }else{
                curr_arr[j] = 0;
            }
 
        }
        next_arr = curr_arr;
    }
    
    cout<< next_arr[n]<<endl;
   
 
    return 0;   
}