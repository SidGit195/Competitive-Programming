#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> divisors[N];                    // 2-D Array

int main(){
    
    for(int i=2; i<N; ++i){
        for(int j=i; j<N; j += i){
            divisors[j].push_back(i);
        }
    }

    for(int i=1; i<N; ++i){
        for(int div: divisors[i]){
            cout << div << " ";
        }
        cout << endl;
    }

}
