/*
    # Binary Search monotonic function par lagta hai (either increasing or decreasing)
    # or B.S. we can apply on a predicate function (ek aisa function jo true or false return kare)
    ex:-    T T T T F F F F F  (MONOTONIC PREDICATE FUN.)
    ex:-    F F F F T T T T T 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin >> v[i];

    int to_find;
    cin >> to_find;

    int lo=0, hi=n-1;
    while(hi - lo > 1){
        int mid = (lo + hi)/2;

        if(v[mid] < to_find)
            lo = mid + 1;
        else
            hi = mid;
    }

    if(v[lo] == to_find)
        cout << lo << endl;
    else if(v[hi] == to_find)
        cout << hi << endl;
    else
        cout << "Not Found";
    
    return 0;
}