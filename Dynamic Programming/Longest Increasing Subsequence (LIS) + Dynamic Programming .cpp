/*
    Array:- 10 9 2 5 3 7 101 18
    subsequence:- 9 5 101           // continuous number (order must be same), subset
*/


// Question : To find out length of longest increasing subsequence

#include <bits/stdc++.h>
using namespace std;
const int N = 25e2 + 10;
vector<int> a(N);
int dp[N];

int lis(int i){
    if(dp[i] != -1) return dp[i];
    int ans = 1;
    for(int j=0; j<i; ++j){
        if(a[j] < a[i]){
            ans = max(ans, lis(j)+1);
        }
    }
    return dp[i] = ans;
}

// T.C. : O(calls X loops) = O(N^2)

int main(){
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    int ans = 1;
    for(int i=0; i<n; ++i){
        ans = max(ans, lis(i));
    }
    cout << ans;

    return 0;
}


/*

    # Input
8
10 9 2 5 3 7 101 18

*/