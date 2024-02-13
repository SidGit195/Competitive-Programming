/*
    # for back tracking take help of imazination of code in mind
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> valid;

// if we not pass str with ref. than it takes O(n) time so to reduce time...
void generate(string &s, int open, int close){
    if(open == 0 && close == 0){
        valid.push_back(s);
        return;
    }

    if(open > 0){
        s.push_back('(');
        generate(s, open-1, close);
        s.pop_back();                       // back tracking step, bcz we passing string by reference (agar reference ke sath pass nahi karte to es step ke jarurat nahi hoti), taki pichali wale call effect na ho
    }

    if(close > 0){
        if(open < close){
            s.push_back(')');
            generate(s, open, close-1);
            s.pop_back();                       // back tracking step
        }
    }

}

int main(){
    int n;
    cin >> n;
    string s;

    generate(s, n, n);

    for(auto &ele: valid)
        cout << ele << " ";
    cout << endl;
    return 0;
}