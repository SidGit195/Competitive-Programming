#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; ++i)
        cin >> v[i];
    
    sort(v.begin()+2, v.end());         // O(nlog(n))       
    // best of types sort   --> introsort algorithm (3 sorting algorithm mixture --> quick, heap, insertion)
    // first element address --> from where you are starting sorting (&a[0])
    // last element address ---> last element ke just aage wale element ka address

    for(int i=0; i<n; i++)
        cout << v[i] << " ";
    cout << endl;

    return 0; 
}