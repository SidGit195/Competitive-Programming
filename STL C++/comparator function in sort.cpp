#include <bits/stdc++.h>
using namespace std;

// comparator function me ulta hota hai false me return karta hai 
// trick jo return karwana hai use simply likh do
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first)
        return a.first < b.first;           // jo chahiye wo he return kardo
    return a.second > b.second;
}

// very simple approach forget all above
// During output in cmp function
// return a < b     -->     means phela element dusare se chhota hona chahiye   (incresing order)
// return a > b     -->     means phela element dusare se bada hona chahiye     (decresing order)

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);

    for(int i=0; i<n; ++i)
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end(), cmp);      
    for(int i=0; i<n; ++i)
        cout << a[i].first << " " << a[i].second << endl;;
    cout << endl;

    return 0;
}