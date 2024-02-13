#include <bits/stdc++.h>
using namespace std;   
int dp[1005][1005];         // changing value i or j hai to dp array bhi enka hi banega

int lcs(int i, int j, string &s1, string &s2){
    if(i < 0 || j < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    // remove 1 char from s1
    int ans = lcs(i-1, j, s1, s2);
    // remove 1 char from s2
    ans = max(ans, lcs(i, j-1, s1, s2));
    // remove 1 char from both s1 & s2
    ans = max(ans, lcs(i-1, j-1, s1, s2) + (s1[i] == s2[j]));

    return dp[i][j] = ans;
}

int longestCommonSubsequence(string text1, string text2) {
    memset(dp, -1, sizeof(dp));
    return lcs(text1.size()-1, text2.size()-1, text1, text2);
}    

// T.C. = O(N^2)   

int main(){
    string text1 = "abcde", text2 = "ace";
    cout << longestCommonSubsequence(text1, text2);
    return 0;
}



// solve extra dp question mentioned in the video
