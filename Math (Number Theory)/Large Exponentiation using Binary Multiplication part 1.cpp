#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
// a <= 10^9, b <= 10^9, M <= 10^9


// case1: when a is very high
// a <= 10^18 || a = 2^1024
// concept:  (a^b)%M == ((a%M)^b)%M     {a ko phele he chhota bnalo}
int binExp(int a, int b){
    // a = a%M;
    // a = binExp(2, 1024);             // use this things when a is high
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

}