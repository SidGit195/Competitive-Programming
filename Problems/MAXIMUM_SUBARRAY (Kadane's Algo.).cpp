#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int mx = nums[0];
    int sum = 0;

    for(int i=0; i<nums.size(); ++i){
        sum += nums[i];
        mx = max(mx, sum);

        if(sum < 0)
            sum = 0;
    }

    cout << mx << endl;

    return 0;
}



/* 
    # kadane's Algo

step 1: mx = nums[0], sum = 0;
step 2: sum += nums[i]; || mx = max(mx, sum);
step 3: if(sum < 0) doesn't contribute in further more so, restart sum = 0;

*/