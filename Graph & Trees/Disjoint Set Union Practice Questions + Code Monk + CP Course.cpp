// Hackerearth Question Link: https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int parent[N];
int size[N];
multiset<int> sizes;

void make(int v){
    parent[v] = v;
    size[v] = 1;
    sizes.insert(1);
}

int find(int v){
    if(parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void merge(int a, int b){
    sizes.erase(sizes.find(size[a]));
    sizes.erase(sizes.find(size[b]));

    sizes.insert(size[a] + size[b]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        merge(a, b);
        size[a] += size[b];
    }
}


int main(){
    int n, q;
    cin >> n >> q;

    for(int i=1; i<=n; ++i)
        make(i);

    while(q--){
        int u, v;
        cin >> u >> v;
        Union(u, v);
        if(sizes.size() == 1){
            cout << 0 << endl;
        }else{
            int mn = *(sizes.begin());
            int mx = *(--sizes.end());
            cout << mx - mn << endl;
        }
    }

    return 0;
}