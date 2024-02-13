// Link: https://atcoder.jp/contests/dp/tasks/dp_e

#include <bits/stdc++.h>
using namespace std;
int wt[105], val[105];
long long dp[105][100005];

// for min weight 
long long func(int ind, int value_left){
    if(value_left == 0) return 0;
    if(ind < 0) return 1e15;
    if(dp[ind][value_left] != -1) return dp[ind][value_left];
    // Donot Choose
    long long ans = func(ind-1, value_left);
    // Choose
    if(value_left - val[ind] >= 0)
        ans = min(ans, func(ind-1, value_left - val[ind]) + wt[ind]);
    return dp[ind][value_left] = ans;
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n >> w;

    int max_value = 1e5;
    for(int i=max_value; i>=0; --i){
        if(func(n-1, i) <= w){
            cout << i << endl;
            break;
        }
    }
    return 0;
}