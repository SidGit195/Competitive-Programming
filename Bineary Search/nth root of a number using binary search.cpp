#include <bits/stdc++.h>
using namespace std;

double eps = 1e-6;          // . ke baad 5 digit tak low and high equal honge so 5 digit tak accurate hoga
double multiply(double mid, int n){
    double ans = 1;
    for (int i = 0; i < n; ++i)
    {
        ans *= mid;
    }
    return ans;
}

int main(){ 
    double x;
    int n;
    cin >> x >> n;
    double lo=1, hi=x, mid;

    while(hi - lo > eps){
        mid = (lo + hi)/2;

        if(multiply(mid, n) < x){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }

    cout << lo << endl;

    return 0;
}


// Time Complexity : Nlog(n*(10^d))  where d = precision digits , N = nth root, n = value whose root we are finding