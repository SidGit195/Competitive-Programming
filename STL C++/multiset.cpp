#include <bits/stdc++.h>
using namespace std;

void printSet(multiset<string> &s){
    cout << "SIZE: " << s.size() << endl;
    for(string value: s)
        cout << value << endl;


}

int main(){
    multiset<string> s;
    s.insert("abc");                // log(n)   
    s.insert("xyz");
    s.insert("hello");
    s.insert("sbbs");
    s.insert("abc");                // multiset can store duplicate values, in a sorted order
    // auto it = s.find("abc");        // log(n)
    // if(it != s.end())
    //     s.erase(it);             // --> delete value only on that index
    // s.erase("xyz");              // --> delete from everyplace where it is present
    
    printSet(s);
    return 0;
}