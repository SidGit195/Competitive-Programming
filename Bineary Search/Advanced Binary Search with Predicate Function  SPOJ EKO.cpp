/*
    # 10^5 se bade array globally declare karne chahiye warna segment fault aa jata hai

    // Concept of Question
    # 0 height par kaatege to obvious m ko satisfy kar dega 
    # func(h) -->   T T T T T F F F F F     (aakhri true find karna hai)
      height  -->   0 1 ...
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n;
long long m;
long long trees[N];

bool isWoodSufficient(int h){
    long long wood = 0;
    for(int i=0; i<n; ++i){
        if(trees[i] > h){
            wood += trees[i] - h;
        }
    }
    return wood >= m;
}

int main(){ 
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        cin >> trees[i];

    long long lo = 0, hi = 1e9, mid;
    // T T T T F F F F 
    while(hi - lo > 1){
        mid = (hi + lo)/2;

        if(isWoodSufficient(mid))
            lo = mid;
        else
            hi = mid-1;
    }
    if(isWoodSufficient(hi))
        cout << hi;
    else
        cout << lo;

    return 0;
}


// Time Complexity: O{n(log(H))} where H = max. height of the tree,  n= no. of trees