/*
------------------- Dijkstra Algorithm -------------------------
# used for directed edges
# used for +ve edges
# pick up any source vertex and find min. distance of all the vertex from the source vertex (when to use)

Time Complexity: O ( V + E l o g V )
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N];

void dijkstra(int source){
    vector<int> vis(N, 0);
    vector<int> dist(N, INF);

    set<pair<int, int>> st;             // first for dist, second for vertex

    st.insert({0, source});
    dist[source] = 0;

    while(st.size() > 0){
        auto node = *st.begin();        // st.begin give iteration & value = *it
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v] = 1;

        for(auto child: g[v]){
            int child_v = child.first;
            int wt = child.second;

            if(dist[v] + wt < dist[child_v]){       // vertex relaxation
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});    // log(V)
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >>  m;

    for(int i=0; i<m; ++i){
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});        // x --wt--> y
    }
}
