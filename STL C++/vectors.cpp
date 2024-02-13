#include <bits/stdc++.h>
using namespace std;

// vectors are dynamic arrays & it allocates continous memory.
void printVec(vector<int> v){
    cout << "size: " << v.size() << endl;
    for(int i=0; i<v.size(); ++i){
        // v.size()  --->  O(1)
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);         // O(1)
        // printVec(v);
    }

    printVec(v);


    cout << "--------------------------------------------" << endl;
    vector<int> v1(6);           // vector of size 6;
    v1.push_back(44);            // O(1)

    cout << endl;
    printVec(v1);


    cout << "--------------------------------------------" << endl;
    vector<int> v2(3, 9);       // 3 size ka vector jiski saare value 9 ho
    v2.pop_back();           // O(1)
    printVec(v2);

    vector<int> v3 = v2;    // O(n) --> expensive operation --> so use always reference --> reference pass karne se copy nahi banega or humare time complexity decrease ho jayegi        // you can directly copy a vector but we can not copy in array (wo pointer copy hota hai usme same array banta ex. int A[] = a )

    return 0;
}