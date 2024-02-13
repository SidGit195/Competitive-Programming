/*
    # all_of
    # none_of
    # any_of

    # above all the algo return true or false
    
    # why use --> to reduce code
*/

#include <bits/stdc++.h>
using namespace std;

bool isPositive(int x){
    return x>0;
}

int main(){
    // lamda function == [](int x){return x+2;}       // bina loop lagaye har element ke liye check karna
    auto sum = [](int x, int y){return x+y;};
    cout << sum(2, 4) << endl;

    vector<int> v = {2, -8, -10, -1};
    cout << all_of(v.begin(), v.end(), [](int x){return x > 0;}) << endl;       // if all +ve --> 1
    cout << all_of(v.begin(), v.end(), isPositive) << endl;

    cout << any_of(v.begin(), v.end(), [](int x){return x > 0;}) << endl;       // if any +ve --> 1

    cout << none_of(v.begin(), v.end(), [](int x){return x > 0;}) << endl;      // if none of +ve --> 1
    return 0;
}