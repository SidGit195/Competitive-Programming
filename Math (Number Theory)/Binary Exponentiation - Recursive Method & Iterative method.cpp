/*
    # pow(x, y) --> return a double value
    and we know that double can store large value but it is not accurate (for large values)
    so we generally avoide pow(x, y) in CP

*/


#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

// a -> base, b -> power
int binExpRecur(int a, int b){
    if(b==0) return 1;

    int res = binExpRecur(a, b/2);
    if(b&1)
        return (a * ((res * 1ll * res) % M)) % M;
    else
        return (res * 1ll * res)%M;
}

// b ke binary ka bit check karna hai
// a = 3, b = 13(1101)
int binExpIter(int a, int b){
    int ans = 1;
    while(b){
        if(b&1){
            ans = (ans * 1ll * a)%M;
        }
        a = (a * 1ll * a)%M;
        b >>= 1;
    }

    return ans;
}

int main(){
    int a = 2, b = 10;
    cout << binExpRecur(2, 10) << endl;
    cout << binExpIter(2, 10);
}