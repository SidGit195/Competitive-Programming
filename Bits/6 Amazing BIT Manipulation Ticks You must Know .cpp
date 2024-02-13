#include <bits/stdc++.h>
using namespace std;

void printBinary(int nums){
    for(int i=10; i>=0; --i){
        cout << ((nums >> i) & 1);
    }
    cout << endl;
}

int main(){
    // for(int i=0; i<8; ++i){
    //     printBinary(i);    //     if(i&1){                         // for checking no. is odd or even  (fast operation comparision with modulo)
    //         cout << "Odd" << endl;
    //     }else{
    //         cout << "Even" << endl;
    //     }
    // }

    //------------------------------------------
    // int n=5;
    // cout << (n>>1) << endl;             // n/2          (fast operation compare to traditional divide and multiply)
    // cout << (n<<1) << endl;             // n*2
    
    //------------------------------------------
    // for(char c='A'; c<='D'; ++c){
    //     cout << c << ":  ";
    //     printBinary(int(c));
    // }
    // cout << endl;
    // for(char c='a'; c<='d'; ++c){
    //     cout << c << ":  ";
    //     printBinary(int(c));
    // }

    // char A = 'A';
    // char a = 'A' | (1<<5);                          // 1 << 5  ==  ' '
    // cout << a << endl;
    // cout << (char)(a & ~(1<<5)) << endl;

    // cout << (char)(1<<5) << endl;
    // printBinary(int(' '));
    // cout << (char)('B' | ' ') << endl;              // Upper --> lower  => or with ' '

    // printBinary(int('_'));
    // cout << char('t' & '_') << endl;                // Lower --> Upper  => and with '_'


    //------------------------------------------
    /*
        # clear LSB's
        # ith bit tak saare bits unset kar dena
        00000111011     given
        00000100000     output
        11111100000
        00000011111
        00000100000  -  1
    */
    // printBinary(59);
    // int a = 59;
    // int i = 4;
    // int b = (a & (~((1 << (i+1)) - 1)));
    // printBinary(b);

    // // # clear MSB's
    // i = 3;
    // int c = (a & ((1 << (i+1)) - 1));
    // printBinary(c);



    //------------------------------------------
    // # Check any number is power of 2 or not
    /*
        # Logic
        00010000  ---> any number of power of 2 is in this form
        00001111
    */
    int x = 17;

    if(x & (x-1))               // non-zero
        cout << "not power of 2";
    else
        cout << "number is in form of power of 2";

    return 0;
}