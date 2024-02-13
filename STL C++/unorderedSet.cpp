#include <bits/stdc++.h>
using namespace std;

void printUSet(unordered_set<string> &s){
    cout << "SIZE: " << s.size() << endl;
    for(string value: s)
        cout << value << endl;


}

int main(){
    unordered_set<string> s;
    s.insert("abc");                // log(1)   -->     hash tables is used
    s.insert("xyz");
    s.insert("hello");
    s.insert("sbbs");
    s.insert("abc");                
    auto it = s.find("abc");        // log(1)
    if(it != s.end())
        s.erase(it);
    s.erase("xyz");
    
    printUSet(s);
    return 0;
}


// unordered_set<pair<int, int>> ---------> not allowed