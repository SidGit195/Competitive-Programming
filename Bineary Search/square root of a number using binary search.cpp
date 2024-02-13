#include <bits/stdc++.h>
using namespace std;

double eps = 1e-6;          // . ke baad 5 digit tak low and high equal honge so 5 digit tak accurate hoga

int main(){ 
    double x;
    cin >> x;
    double lo=1, hi=x, mid;

    while(hi - lo > eps){
        mid = (lo + hi)/2;

        if(mid*mid < x){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }

    cout << lo << endl;

    return 0;
}