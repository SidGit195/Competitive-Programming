/*
    # ~ ulta kar deta hai binary ko
    # ^ == XOR
*/

#include <bits/stdc++.h>
using namespace std;

void printBinary(int num){
    for(int i=10; i>=0; --i){
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

int main(){ 
    printBinary(9);
    int a = 9;
    int i=3;

    if((a & (1 << i)) != 0)
        cout << "Set Bit" << endl;
    else
        cout << "Not Set Bit" << endl;

    // set bit
    printBinary(a | (1 << 1));
    // unset bit
    printBinary((a & ~(1<<3)));

    // toggle bit
    printBinary(a ^ (1<<2));
    printBinary(a ^ (1<<3));

    // Counting of set bit
    int ct=0;
    for(int i=31; i>=0; --i){
        if((a & (1<<i)) != 0){
            ct++;
        }
    }
    cout << ct << endl;
    // inbuilt function for set bit count
    cout << __builtin_popcountll((1ll << 35)-1) << endl;

    return 0;
}