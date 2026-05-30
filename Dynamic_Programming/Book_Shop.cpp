#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , x;
    cin >> n >> x;
    vector<int> book(n);
    vector<int>page (n);
    for( int &a : book) cin >> a;
    for( int &a : page) cin >> a;
 
    vector<int> next_arr(x+1, 0);
    
    for (int i = n-1;i>= 0 ; i--){
        vector<int>curr_arr(x+1, 0);
        for (int cost = 0 ; cost <= x;cost++){
            int not_take = next_arr[cost];
            int take = 0;
            if (cost >= book[i]){
                take  = page[i] + next_arr[cost - book[i]];
            }
            curr_arr[cost] = max(not_take , take);
        }
        next_arr = curr_arr;
    }
 
    
    cout<<next_arr[x]<<endl;
   
 
    return 0;   
}