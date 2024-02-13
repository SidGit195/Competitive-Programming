// Difference between ordered maps and unordered maps
// 1. Inbuilt implementation  --> use hash table where as map use tree
// 2. Time Complexity         --> all common inbuilt function --> O(1)
// 3. Valid keys datatype

#include <bits/stdc++.h>
using namespace std;

void printOMap(unordered_map<int, string> &m){
    cout << "SIZE: " << m.size() << endl;
    for(auto &pr: m)
        cout << pr.first << " " << pr.second << endl;
}

int main(){
    unordered_map<int, string> m;
    m[7] = "aljd";          // O(1)
    m[3] = "lajf";
    m[5] = "eyhs";
    m[2] = "inbv";
    auto it = m.find(9);       // O(1)
    if(it == m.end())
        cout << "NO VALUE" << endl;
    else
        cout << (*it).first << ' ' << (*it).second << endl;


    cout << "------------------ 3 point --------------------------" << endl;
    // unordered_map<pair<int, int>, string> mm;        // not allowed this datatype, reason: pair ka inbuilt koi hash function define nahi hota hai 
    map<pair<int, int>, string> mm;

    printOMap(m);
    return 0;
}