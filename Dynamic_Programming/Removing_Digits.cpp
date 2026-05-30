#include <bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin >> n ;
    vector<int> dp(n+1);
    dp[0] = 0;
 
    for (int i = 1; i < n+1 ; i++){
        int num = i;
        int temp = n;
        while (num > 0){
            int digit = num % 10;
           
            if (digit != 0 && num- digit >=0){
                temp = min(temp , 1+dp[i - digit]);
            }
            num/= 10;
        }
        dp[i] = temp;
    }   
 
 
    
    cout << dp[n] << endl;
    return 0;   
}