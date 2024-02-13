/*
    # DFS (Depth First Search)
    --> Phele graph ke depth me jana hai tab tak jab tak end na mil jaye than return 

*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<int> g[N];
bool vis[N];

/* 
//written by me
void dfs(int vertex){
    cout << vertex << " ";
    vis[vertex] = true;

    for(int j: g[vertex]){
        if(!vis[j]) dfs(j);
    }
}
*/

void dfs(int vertex){
    // Take action on vertex after entering the vertex
    cout << vertex << endl;
    vis[vertex] = true;
    for(int child: g[vertex]){
        // Take action on child before entering the child node
        cout << "par " << vertex << ", child " << child << endl;
        if(vis[child]) continue;
        dfs(child);
        // Take action on child after exiting child node
    }
    // Take action on vertex before exiting the vertex
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; ++i){
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    
    return 0;
}


// Time Complexity: O(V + E)