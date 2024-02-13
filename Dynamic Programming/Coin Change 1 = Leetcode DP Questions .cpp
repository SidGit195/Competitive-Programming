// Question Link: https://leetcode.com/problems/coin-change/submissions/1163874159/

#include <bits/stdc++.h>
using namespace std;
int dp[10010];

int func(vector<int>& coins, int amount){
    if(dp[amount] != -1) return dp[amount];
    if(amount == 0) return 0;

    int ans = INT_MAX;
    for(int coin: coins){
        if(amount - coin >= 0)
            ans = min(ans + 0ll, func(coins, amount - coin) + 1ll);
    }
    return dp[amount] = ans;
} 

int coinChange(vector<int>& coins, int amount) {
    memset(dp, -1, sizeof(dp));
    int ans = func(coins, amount);

    return ans == INT_MAX ? -1 : ans;     
}

int main(){
    vector<int> coins = {2};
    cout << coinChange(coins, 3);
    return 0;
}