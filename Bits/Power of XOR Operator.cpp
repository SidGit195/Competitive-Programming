/*
    # XOR TABLE
    1 0  -->  1
    0 1  -->  1
    0 0  -->  0
    1 1  -->  0

    # Imp XOR property
    1.  x ^ x  ==  0
    2.  x ^ 0  ==  x
    3.  x ^ y ^ z  ==  x ^ z ^ y  ==  y ^ z ^ x     (Order not matters in XOR)

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int a = 4, b = 6;

    a = a ^ b;
    b = b ^ a;      // b = b ^ (a ^ b) = b ^ b ^ a = 0 ^ a = a
    a = a ^ b;      // a = (a ^ b) ^ a = a ^ a ^ b = 0 ^ b = b

    cout << a << " " << b << endl; 

    /*
    # Question
    --> Given array a of n integers. All integers
    are present in even count except one.
    Find that one integer which has odd count 
    in O(N) time complexity and O(1) space.
    
    => N < 10^5
    a[i] < 10^5

    */                 
    int n; 
    cin >> n;
    int x;
    int ans=0; 
    for(int i=0; i<n; i++){
        cin >> x;
        ans ^= x;
    }            
    cout << ans << endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    return 0;
}