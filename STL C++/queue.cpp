#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<string> q;
    q.push("abc");
    q.push("def");
    q.push("ghi");
    q.push("jkl");

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}