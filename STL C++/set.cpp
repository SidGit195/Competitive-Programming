/*
    A set is a data structure that stores unique elements of the same type in a sorted order.
*/

#include <bits/stdc++.h>
using namespace std;

void printSet(set<string> &s){
    cout << "SIZE: " << s.size() << endl;
    for(string value: s)
        cout << value << endl;


}

int main(){
    set<string> s;
    s.insert("abc");                // log(n)
    s.insert("xyz");
    s.insert("hello");
    s.insert("sbbs");
    s.insert("abc");                // set store only unique elements
    auto it = s.find("abc");        // log(n)
    if(it != s.end())
        s.erase(it);
    s.erase("xyz");
    
    printSet(s);
    return 0;
}