/*
    we have to find min spanning tree from a given graph
    min means min cost
    spanning tree means a connected 1 tree
    simply saare vertices aapse me connected hoge with min weighted edges
    
    krushkal algorithm is used for undirected graph
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int parent[N];
int size[N];

void make(int v){
    parent[v] = v;
    size[v] = 1;
}

int find(int v){
    if(parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        if(size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main(){
    int n, m;       // n --> nodes,  m --> edges
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges;         // phele weight, vertexes

    for(int i=0; i<m; ++i){
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt, {u, v}});
    }

    sort(edges.begin(), edges.end());

// independent graph nodes  (abhi edge nahi daale hai sirf nodes create ke hai)
    for(int i=1; i<n; ++i)
        make(i);


    int total_cost = 0;
    for(auto &edge : edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if(find(u) == find(v)) continue;        // Condition for loop

        Union(u, v);
        total_cost += wt;
        cout << u << " " << v << " == " << wt << endl;
    }

    cout << total_cost << endl;
}

/*
    # Input
6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3 
3 6 8
2 6 7

*/