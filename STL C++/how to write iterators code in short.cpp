#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v){
    cout << "Size: " << v.size() << endl;
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main(){
    vector<int> v = {2, 4, 6, 8, 10};
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // vector<int> ::iterator it;

    for(auto it=v.begin(); it!=v.end(); it++)           // auto == vector<int> ::iterator
        cout << (*it) << " ";
    cout << endl;

    for(int value: v)                   // range based for loop, it works for all containers, value me v ka data copy ro raha hai costly use reference
        cout << value << " ";
    cout << endl;
    

    cout << "--------------------------------------" << endl;
    vector<pair<int, int>> v_p = {{1,2}, {2,3}, {3,4}, {4,5}};
    for(auto &value: v_p)                 // auto == pair<int, int>
        cout << value.first << " " << value.second << endl;
    cout << endl;

    cout << "--------------------------------------" << endl;
    auto a = 2.3;
    cout << a << endl;

    return 0;
}