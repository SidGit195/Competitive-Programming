/*
    # (A * B) % M == 1
    -> B is called Modular Multiplicative inverse (MMI) of A
    -> ((A%M) * (B%M)) % M == 1
    -> r = B%M
    -> 1 <= r <= M-1
    -> 1 <= B <= M-1    (assumtion)


    => M-1
    -> Loop: B = 1 to M-1
    -> Condn: (A * B) % M == 1
    -> T.C. == O(M)
    -> MMI of A with M: O(M)

Imp ==> MMI defined iff A and M are co-prime{gcd(A, M) == 1}




    => M-2 (Fermat little Theorem) {optimized Way}

    -> Case1: when M: Prime
    -> A^ (M-1)  = congrancy =  1 mod(M)      <-{Theorem Result}  |  {condn} -> where M is prime Number + A is not multiple of M
    -> A^ (M-2)  = congrancy =  A^ (-1) mod(M)
    -> A^ (M-2) % M  ==  A^ (-1)    {Meaning of step 3}
    -> binExp(A, M-2, M)        // Log(N)

    -> Case2: When M: Non-Prime
    -> Solve by Extended Euclid Algorithm

*/


#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int binExp(int a, int b, int m){
    int ans=1;
    while(b>0){
        if(b&1){
            ans = (ans * 1ll * a) % m;

        }
        a = (a * 1ll * a) % m;
        b >>= 1;
    }

    return ans;
}

/*
    # Question
    -> There are N children and K toffees.  K < N
    Count the number of ways to distribute toffee among N students 
    such that each student get one toffee % M where M = 10^9 + 7;
    N < 10^ 6  ||  K < N < 10^ 6 
    Q < 10^ 5

    Ans: NCK    {nCr}
    -> n! / ((n-r)! * r!)
*/


const int N = 1e6+10;
int fact[N];

int main(){
    fact[0] = 1;
    for(int i=1; i<N; ++i){
        fact[i] = (fact[i-1] * 1ll * i) % M;
    }

    int q;
    cin >> q;
    while(q--){
        int n, k;
        cin >> n >> k;
        int ans = fact[n];
        int den = (fact[n-k] * 1ll * fact[k]) % M;
        ans = ans * binExp(den, M-2, M);
        cout << ans << endl;
    }

}


/*
IMP ==> (a / b) % M, wale questions me a ko b se divide nahi karna hai 
        b ka MMI nikal karke multiply karwa daina hai
*/