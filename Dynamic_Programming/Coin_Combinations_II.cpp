#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , x ;
    cin >> n >> x;
    vector<int> coins(n);
    for (int &a : coins) cin>>a;
 
 
    const int MOD  = 1e9 +7;
    vector<int> next_arr(x+1, 0);
    next_arr[0] = 1;
 
 
    for (int i = n-1 ; i >=0 ; i--){
        vector<int>curr_arr(x+1,0);
        curr_arr[0] = 1;
        for (int j = 1; j<=x ; j++){
            int n_take = next_arr[j];
            int take = 0;
            if (j- coins[i] >=0){
                take = curr_arr[j-coins[i]];
            }
            curr_arr[j] = (take + n_take) % MOD;
 
        }
        next_arr = curr_arr;
 
    }
 
    cout<< next_arr[x] << endl;
    return 0;
}