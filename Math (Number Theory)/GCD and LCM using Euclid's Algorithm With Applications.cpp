/*
    Important Formula
    # number1 X number2 == LCM X GCD(HCF)
*/

#include<bits/stdc++.h>
using namespace std;

// a -> dividend, b -> divisor
int gcd(int a, int b){
    // if(a%b == 0)
    //     return b;
    if(b == 0) return a;
    return gcd(b, a%b);
}

// Time Complexity : O(log(n))   -->     in case of divisor == 2

int main(){
    cout << gcd(12, 18) << endl;
    cout << gcd(18, 12) << endl;
    cout << "LCM: " << 12*18/gcd(18, 12) << endl;

    // gcd in built function
    cout << __gcd(12, 18) << endl;      // log(n)
    // gcd(gcd(a,b), c)  -->  gcd of three numbers


    // minimum fraction of two number
    // a/b  ==  (a/gcd(a,b)) / (b/gcd(a,b))
}