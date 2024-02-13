/*
    # HackerEarth Question: https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/name-count/
*/


#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10; 
int fact[N];

// kCn
// k! / ((k-n)! * n!) * n!

int binExp(int a, int b, int m){
    int ans = 1;
    while(b > 0){
        if(b & 1){
            ans = (ans * 1ll * a) % m;
        }
        a = (a * 1ll * a) % m;
        b >>= 1;
    }

    return ans;
}

int main(){
    fact[0] = 1;
    for(int i=1; i<N; ++i){
        fact[i] = (fact[i-1] * 1ll * i) % M;
    }

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int ans = fact[k];
        ans = (ans * 1ll * fact[n]) % M;
        int den = (fact[k-n] * 1ll * fact[n]) % M;
        ans = (ans * 1ll * binExp(den, M-2, M)) % M;

        cout << ans << endl;
    }
    // O(t * log(N))
}
