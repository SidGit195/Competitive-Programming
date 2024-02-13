// Subsets Leetcode question
// Subsets Calculation using Bit-Masking

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums){
    int n = nums.size();
    int subset_ct = (1 << n);       // 2^n
    vector<vector<int>> subsets;
    for(int mask=0; mask < subset_ct; ++mask){
        vector<int> subset;
        for(int i=0; i<n; ++i){                 // 0 to n-1 saare possible combination cover kar dega
            if((mask & (1<<i)) != 0){
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset);
    }
    // O(n*2^n)
    return subsets;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin >> v[i]; 

    auto all_subsets = subsets(v);

    for(auto subset: all_subsets){
        for(int ele: subset){
            cout << ele << " ";
        }
        cout << endl;
    }
}



/*
3
2 4 5 
 
ith bit represent ith element of nums 
0 -- 000 --> []
1 -- 001 --> [2]
2 -- 010 --> [4]
3 -- 011 --> [2, 4]
4 -- 100 --> [5]
5 -- 101 --> [2, 5]
6 -- 110 --> [4, 5]
7 -- 111 --> [2, 4, 5]
*/