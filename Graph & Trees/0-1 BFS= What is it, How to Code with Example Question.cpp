/* # Finding shortest distance b/w two vertices having weights of edges either 0 or 1 using BFS
    -> 0 weight wale edge ko queue ke front me daal do
    -> 1 weight wale edge ko queue ke back me
    -> ek chhota level or ek bada level
    -> 0-1 BFS me visited array ke jarurat nahi padti
*/

/*
    # Question
    -> what is the minimum number of edges he needs to reverse in order to have at least 
    one path from vertex 1 to N, where the vertices are numbered from 1 to N.

    Link: https://www.youtube.com/watch?v=SQOQ99stCas&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=94
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int INF = 1e9;

vector<pair<int, int> > g[N];
vector<int> level(N, INF);
int n, m;

int bfs(){
    deque<int> q;
    q.push_back(1);
    level[1] = 0;

    while(!q.empty()){
        int cur_v = q.front();
        q.pop_front();

        for(auto child: g[cur_v]){
            int child_v = child.first;
            int wt = child.second;
            if(level[cur_v] + wt < level[child_v]){
                level[child_v] = level[cur_v] + wt;
                if(wt == 1){
                    q.push_back(child_v);
                }else{
                    q.push_front(child_v);
                }
            }
        }
    }
    return level[n] == INF ? -1 : level[n];
}


int main(){
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int x, y;
        cin >> x >> y;
        if(x == y) continue;        // ignore selfloops
        g[x].push_back({y, 0});
        g[y].push_back({x, 1});
    }

    cout << bfs() << endl;
    return 0;
}


/*
    # Input
7 7 
1 2 
3 2
3 4
7 4
6 2
5 6
7 5

*/