/*
    # pow(x, y) --> return a double value
    and we know that double can store large value but it is not accurate (for large values)
    so we generally avoide pow(x, y) in CP

    # O(n) 
    int ans = 1;
    for(int i=0; i<y; ++i){
        ans *= x;
    }
    cout << ans << endl;
    but this is not efficient to calculate power of a number
    so we use binary exponentiation

    # Binary Exponentiation
    # O(logn)
    # a^b
    # b = 13(1101)
    # 2^13 = 2^8 * 2^4 * 2^1
    ----------
    # 2^8 = 2^4 * 2^4
    # 2^4 = 2^2 * 2^2
    # 2^2 = 2^1 * 2^1
    # 2^1 = 2^0 * 2^0
    # 2^0 = 1
    ----------
    It's a divide and conquer approach || pehle b ko tod do 2 parts me again and again then ektah kar do
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
// Time Complexity: O(log(b))
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