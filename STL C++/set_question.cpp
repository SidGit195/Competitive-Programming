/*
Given N strings, print unique strings in lexiographical order
N <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

void printSet(set<string> s){
    cout << "SIZE: " << s.size() << endl;
    for(auto &value: s)
        cout << value << endl;
}

int main(){
    set<string> s;
    int n;
    cin >> n;

    for(int i=0; i<n; ++i){
        string st;
        cin >> st;
        s.insert(st);
    }

    printSet(s);
    return 0;
}