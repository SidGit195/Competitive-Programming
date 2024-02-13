// it+1 is not allowed but it++ allowed
// map pairs are in key: value formet
// .size(), .find(), .erase(), .clear()  --->  works in all almost 

#include <bits/stdc++.h>
using namespace std;

void printMap(map<int, string> &m){
    cout << m.size() << endl;
    for(auto &pr: m)
        cout << pr.first << " " << pr.second << endl;
}

int main(){
    map<int, string> m;
    m[1] = "xyz";               // O(lon(n)) ---> of insertion as well as of access from map
    m[9] = "abc";
    m[3] = "pqr";
                                // unique keys, stored in sorted order
    m[9] = "sla";               // duplicate keys is not allowed in map, it simply replace previous value
    m.insert({5, "mno"});
    map<int, string> ::iterator it;

    for(it = m.begin(); it!=m.end(); ++it){
        cout << (*it).first << " " << (*it).second << endl;
    }

    cout << "---------------------------------------------" << endl;
    // printMap(m);
    auto itt = m.find(9);       // O(log(n))
    if(itt != m.end())
        cout << "NO VALUE" << endl;
    else
        cout << (*itt).first << ' ' << (*itt).second << endl;

    cout << "---------------------------------------------" << endl;
    // m.erase(9);     // log(n)      // take inputs as iterator and key
    // printMap(m);
    auto ittt = m.find(18);
    if(ittt != m.end())
        m.erase(ittt);

    m.clear();      // clear the map

    cout << "---------------------------------------------" << endl;

    map<string, string> mm;
    mm["alkja"] = "jaljdsla";       // s.size() * log(n)  where s -->> string ,  farak padta hai jab bhot badi string ho
    
    return 0;
}