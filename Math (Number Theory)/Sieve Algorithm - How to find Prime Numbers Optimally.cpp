#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
vector<bool> isPrime(N, 1); 
// Q <= 10^ 7, N <= 10^ 7

int main(){
    isPrime[0] = isPrime[1] = false;

    // Sieve Algorithm
    for(int i=2; i<N; ++i){
        if(isPrime[i] == true){
            for(int j=2*i; j<N; j += i){
                isPrime[j] = false;
            }
        }
    }
    // sieve :--> N * log(log(N))

    int q;
    cin >> q;
    while(q--){
        int num;
        cin >> num;
        if(isPrime[num]){
            cout << num << ": Prime" << endl;
        }else{
            cout << num << ": Not-prime" << endl;
        }
    }
}


/*
    # Time Complexity Before Sieve: Q * sqrt(N)
    # After: Q * O(1)
*/