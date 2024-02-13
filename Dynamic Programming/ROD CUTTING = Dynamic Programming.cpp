// Question Link: https://www.geeksforgeeks.org/problems/rod-cutting0840/1

#include <bits/stdc++.h>
using namespace std;
int dp[1010]; 
    
// unbounded knapsack 
int func(int len, vector<int> &prices){                 // max value for length
    if(dp[len] != -1) return dp[len];
    if(len == 0) return 0;

    int ans = 0;
    for(int len_to_cut = 1; len_to_cut <= prices.size(); ++len_to_cut){
        if(len - len_to_cut >= 0){
            ans = max(ans, func(len - len_to_cut, prices) + prices[len_to_cut - 1]);
        }
    }

    return dp[len] = ans;
}

// T.C. = O(N^2)

int cutRod(int price[], int n) {
    memset(dp, -1, sizeof(dp));
    vector<int> prices(price, price+n);         // changing array into vector
    return func(n, prices);
}

int main(){

    return 0;
}