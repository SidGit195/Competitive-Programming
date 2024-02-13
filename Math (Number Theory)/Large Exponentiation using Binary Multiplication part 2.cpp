#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
// a <= 10^9, b <= 10^9, M <= 10^9


// case2: when m is a high number
// M = 10^18
int binExp(int a, int b){
    int ans = 1;
    while(b){
        if(b&1){
            ans = binMultiply(ans, a);
        }
        a = binMultiply(a, a);
        b >>= 1;
    } 

    return ans;
}


int binMultiply(long long a, long long b){
    int ans = 0;
    while(b > 0){
        if(b&1){
            ans = (ans + a) % M;
        }
        a = (a + a) % M;
        b >>= 1;
    }
}

int main(){

}