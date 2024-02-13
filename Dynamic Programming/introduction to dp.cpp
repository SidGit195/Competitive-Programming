#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int dp[N];
// Top Down Approach        ---->   in recursion which is used here (starting from higer{n} index) || n --> (n-1)+(n-2) || bade problem se chhote ke problem ke aur jana || Luv preferable
// step1: write brute force recursion
// step2: add dp 2 lines

int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    if(dp[n] != -1) return dp[n];           // memoise

    return dp[n] = fib(n-1) + fib(n-2);
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;

    // bottom up Approach       ---->   in iteration (starting from lower{0} index)  || chhote problem se upar jayenge
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; ++i){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << fib(n) << endl;
    return 0;
}


// After memoisation
// Time Complexity converts from 2^n --> n