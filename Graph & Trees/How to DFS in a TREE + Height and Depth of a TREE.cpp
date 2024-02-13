#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
// Tree me dfs ke liye visited array ke jarurat nahi hoti hai kyonki loop to hota nahi hai or parent node visit na kare esliye hum parent pass kar denge

vector<int> g[N];
int height[N], depth[N];

void dfs(int vertex, int par=0){
    for(int child: g[vertex]){
        if(child == par) continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
    }
}

int main(){
    int n;
    cin >> n;

    for(int i=0; i<n-1; ++i){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);

    for(int i=1; i<=n; ++i)
        cout << depth[i] << " " << height[i] << endl;

}


/*
# Input
13
1 2
1 3 
1 13
2 5
3 4 
5 6
5 7
5 8
8 12
4 9
4 10
10 11

*/