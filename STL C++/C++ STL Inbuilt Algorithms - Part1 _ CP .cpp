#include <bits/stdc++.h>
using namespace std;

int main(){
    
    return 0;
}/*
    # all operation are O(n)  -->  in case of array & vector
    # but in case of set & map --> O{log(n)}  -->  syntax --> s.find(13);
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }   

    int min = *min_element(v.begin()+3, v.end());            // return address, pointer in case of array
    cout << min << endl;
    int max = *max_element(v.begin(), v.end());
    cout << max << endl;

    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << endl;

    int ct = count(v.begin(), v.end(), 9);
    cout << ct << endl;

    auto it = find(v.begin(), v.end(), 13);
    if(it != v.end())
        cout << *it << endl;
    else
        cout << "Not Found" << endl;

    reverse(v.begin(), v.end());                            // reverse array, vector, string
    for(auto val: v)
        cout << val << " ";
    cout << endl;

    return 0;
}