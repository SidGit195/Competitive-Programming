#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bool vis[N];
vector<int> g[N];

bool dfs(int vertex, int par){
    vis[vertex] = true;
    bool isLoopExists = false;

    for(int child: g[vertex]){
        if(vis[child] && child == par) continue;
        if(vis[child]) return true;

        isLoopExists |= dfs(child, vertex);
    }

    return isLoopExists;
}

int main(){
    int n, e;
    cin >> n >> e;

    for(int i=0; i<e; ++i){
        int x, y;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    bool isLoopExists = false;
    for(int i=1; i<=n; ++i){
        if(vis[i]) continue;

        if(dfs(i, 0)){
            isLoopExists = true;
            break;
        }
    }
    cout << isLoopExists << endl; 

    return 0;
}



/*
    # Input
8 6
1 2
2 3
2 4
3 5
6 7
1 5

*/