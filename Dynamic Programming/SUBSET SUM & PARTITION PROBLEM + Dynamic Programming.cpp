// Question Link: https://leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>
using namespace std;          

int dp[205][20005];             // jitne variable func me change ho rahe hai utne dimension ka dp banega
bool func(int ind, int k, vector<int> &nums){
    if(dp[ind][k] != -1) return dp[ind][k];
    if(ind < 0) return false;
    if(k == 0)  return true;

    bool result = func(ind-1, k, nums);

    if(k - nums[ind] >= 0)
        result = (result | func(ind-1, k-nums[ind], nums));

    return dp[ind][k] = result;
}

bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto &i: nums)
            sum += i;
        
        if(sum % 2 != 0)
            return false;

        int k = sum/2;
        memset(dp, -1, sizeof(dp));
        return func(nums.size()-1, k, nums);
}

int main(){
    vector<int> nums = {1,5,11,5};
    cout << canPartition(nums);
    return 0;
}