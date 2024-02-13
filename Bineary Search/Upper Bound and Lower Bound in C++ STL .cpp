/*
    # UPPER & LOWER BOUND
    # Array or Vector jis par bhi apply karo wo sorted hone chahiye

    # LOWER BOUND :- agar wo element present hai to wahi found karega warna usse just bada element array me present (element present)
    # UPPER BOUND :- upar bound just bada element he found karega

    # Yeh dono function location he return karte hai
    # in case of array --> pointer  &  vector --> iterator
    
    # Time Complexity --> O{log(n)} where n --> size of array
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    // int a[n];

    // for(int i=0; i<n; i++)
    //     cin >> a[i];
    // sort(a, a+n);           // must for to use lower & upper bound
    // for(int i=0; i<n; i++)
    //     cout << a[i] << " ";
    // cout << endl;

    // int *ptr = lower_bound(a, a+n, 12);
    // if(ptr == (a+n)){
    //     cout << "Not Found";
    //     return 0;
    // }
    // cout << *ptr << endl;

    // int *ptr2 = upper_bound(a+3, a+n, 6);
    // if(ptr == (a+n)){
    //     cout << "Not Found";
    //     return 0;
    // }
    // cout << *ptr2 << endl;


    // in case of set, set to by default sort he hota hai
    set<int> s;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    // auto it = lower_bound(s.begin(), s.end(), 11);          // in case of set and map this notation becames --> O(n)
    auto it = s.lower_bound(11);                               // now it is --> O{log(n)}
    cout << *it << endl;

    map<int, int> m;                                           // key par lower or upper bound use karenge
    return 0;
}