// see video on it 

#include <bits/stdc++.h>
using namespace std;
int dp[310][10010];

int func(int ind, int amount, vector<int>& coins){
    if(amount == 0) return 1;
    if(ind < 0) return 0;
    if(dp[ind][amount] != -1) return dp[ind][amount];

    int ways = 0;
    for(int coin_amount = 0; coin_amount <= amount; coin_amount += coins[ind]){
        ways += func(ind-1, amount - coin_amount, coins);
    }

    return dp[ind][amount] = ways;
}

int coinChange(vector<int>& coins, int amount){
    memset(dp, -1, sizeof(dp));
    return func(coins.size()-1, amount, coins);
}

int main(){
    vector<int> coins = {1, 2, 5};
    cout << coinChange(coins, 5);
    return 0;
}




/*
    -> Combinations must not be repeat
    1112 == 12111   (not count differently)

    -> 2d DP Question

    -> one by one finish all the coins
*/