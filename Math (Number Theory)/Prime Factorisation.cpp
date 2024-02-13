// * kisi bhi number ka sabse chhota divisor (except one) is prime number
// for Non-Prime numbers sqrt(N) se phele ek prime exist karega he

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> prime_factors;
    for(int i=2; i*i<=n; ++i){
        while(n % i == 0){
            prime_factors.push_back(i);
            n /= i;
        }
    }
    if(n > 1)
        prime_factors.push_back(n);

    // O(sqrt(N))
    for(auto prime: prime_factors)
        cout << prime << " ";
}