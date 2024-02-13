/*
# ETF := Eular Totient Function
    N --> count K
    such that 1 <= K <= N || K, N are co-prime

    ex:- 6
        ETF = fi(6) = 2 {1, 5}


    # Formula of ETF Values == n * multiply(1 - 1/p)     where p is all distinct prime factors of n



// # Euler's Theorem
    a^b == congruent == a^(b % fi(n)) % (n) 
    meaning (a^b % M) == (a ^ (b % fi(M))) % M          where M is any number


    * for prime number ETF == fi(Prime No.) == n*(1 - 1/n) == n - 1
    so in case of prime number formula becames
    (a^b % M) == (a ^ (b % (M-1)) % M 

*/


#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

/*
// case1: b <= 10^18
int binExp(int a, long long b){
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
*/

int binExp(int a, long long b, int m){
    int ans = 1;
    while(b > 0){
        if(b&1){
            ans = (ans * 1ll * a) % m;
        }
        a = (a * 1ll * a) % m;
        b >>= 1;
    }

    return ans;
}


int main(){
    // 50 ^ 64 ^ 32
    // since M is prime 
    cout << binExp(50, binExp(64, 32, M-1), M);
    
}