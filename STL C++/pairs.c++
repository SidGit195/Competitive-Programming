#include <bits/stdc++.h>
using namespace std;

int swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    pair<int, string> p;                // pair means 2 values or 2 datatypes
    // p = make_pair(2, "abc");
    // cin >> p.first;
    p = {2, "abcd"};
    pair<int, string> p1 = p;           // copy ja rahe hai not reference
    p1.first = 5;
    pair<int, string> &p2 = p;          // 
    p2.first = 7;
    cout << p.first << " " << p.second << endl;


    cout << "-------------------------------------------" << endl;
    int a[] = {2, 4, 6};
    int b[] = {1, 3, 5};
    pair<int, int> p_array[3];
    p_array[0] = {2, 1};
    p_array[1] = {4, 3};
    p_array[2] = {6, 5};
    swap(p_array[0], p_array[2]);
    for(int i=0; i<3; i++)
        cout << p_array[i].first << " " << p_array[i].second << endl;
    return 0;
}   