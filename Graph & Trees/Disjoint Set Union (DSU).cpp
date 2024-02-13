// used to make sets or grouping of similar things
// finding similar connected components
// Time Complexity: O(alpha(N)) --> almost constant

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int parent[N];
int size[N];

void make(int v){               // make add new node in the current group or set or network independently(means not connected anyone) --> simply creates independent nodes
    parent[v] = v;
    size[v] = 1;
}

int find(int v){                // find gives the root or parent of the node from which it belongs
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);     // path compression by assigning
}

// bade tree ke andar chhota tree jodna hai
void Union(int a, int b){       // a or b alag-alag tree ke parent node ko joddo (concept of adding parent node, node a+b)  --> par(a) + par(b)
    a = find(a);    // bada tree
    b = find(b);    // chhota tree
    if(a != b){
        if(size[a] < size[b])               // union by size
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
    // a == b  -->  dono ka parent same hai means connected hai
}

int main(){
    int n, k;       // n --> nodes , k --> edges

    for(int i=1; i<=n; i++){
        make(i);
    }

    while(k--){
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    int connected_ct = 0;                   // finding connected component

    for(int i=1; i<=n; ++i){
        if(find(i) == i) connected_ct++;
    }

    return 0;
}

//size[i] is the number of the elements in the tree representing the set