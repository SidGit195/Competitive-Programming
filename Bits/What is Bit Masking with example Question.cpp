/*
    # BitMasking  ==  Bit Masking
    see video 62 for better explanation

    We have four fruits
    Apple   --  0    (indexing)
    Orange  --  1
    Banana  --  2
    Lichi   --  3

    -------------------------------------
    We want to calculate common fruit
    -------------------------------------

person + fruit          Bit + Masking
   p1) 2, 3         --> 1100  == 12
    2) 0, 1, 2      --> 0111  == 7
    3) 1, 3         --> 1010  == 10
---> 2 sorted array intersection = O(n) {using 2 pointer approach}
    But we want to reduce time complexity of O(n)
    
    1100
and 0111        (And operation == O(1))
   ------- 
    0100        ---> 2nd fruit is common
   -------

    # Unsigned int == 32 bits
    # unsigned long long == 64 bits
    
*/


// for question see blog https://codeforces.com/blog/entry/73558
#include <bits/stdc++.h>
using namespace std;

void printBinary(int nums){
    for(int i=32; i>=0; --i){
        cout << (1 & (nums >> i));
    }
    cout << endl;
}

/*
    // # Approach M-1
int main(){
    int n;          // num of workers
    cin >> n;
    vector<int> days[n];

    for(int i=0; i<n; ++i){
        int num_days;
        cin >> num_days;
        for(int j=0; j<num_days; ++j){
            int day;
            cin >> day;
            days[i].push_back(day);
        }
    }

    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            // intersection of days[i], days[j]     --->    O(n)    where n --> no. of days
        }
    }
    // O(N^2 * 30)
    return 0;
}

*/

int main(){
    int n;          // num of workers
    cin >> n;
    vector<int> masks(n, 0);            // n size vector, every element of vector 0

    for(int i=0; i<n; ++i){
        int num_days;
        cin >> num_days;
        int mask=0;
        for(int j=0; j<num_days; ++j){
            int day;
            cin >> day;
            mask = (mask | (1<<day));
        }
        masks[i] = mask;
    }
    for(int i=0; i<n; ++i){
        cout << masks[i] << endl;
        printBinary(masks[i]);
    }

    int max_days = 0;
    int person1 = -1;
    int person2 = -1;
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            int intersection = (masks[i] & masks[j]);
            int common_days = __builtin_popcount(intersection);         // O(1)
            if(common_days > max_days){
                max_days = common_days;
                person1 = i;
                person2 = j;
            }
            cout << i << " " << j << " " << common_days << endl;
        }
    }

    cout << endl << person1 << " " << person2 << " " << max_days << endl;

    // O(N^2 * 30)
    return 0;
}



/*
    # Sample Input
5   // people
4   // days
1 4 7 29    // ith day
6 
2 9 1 7 25 29
7 
1 23 4 7 9 11 29
10 
2 28 8 7 9 10 30 21 18 19
4 
1 11 29 7

*/