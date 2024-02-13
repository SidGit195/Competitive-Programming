 #include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;

int graph1[N][N];                       // Matrix Representation
vector<pair<int, int> > graph2[N];      // List Representation

int main(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; ++i){
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;

        graph1[v1][v2] = wt;
        graph1[v2][v1] = wt;

        graph2[v1].push_back({v2, wt});
        graph2[v2].push_back({v1, wt});
    }

    // i, j connected ? || i, j > wt ?  ==> O(1) --> fayada of graph representation
    if(graph1[i][j] == 1){
        // connected
        graph1[i][j];       // for wt
    }

    // wt ? ==> O(N) --> nuksan of List Representation
    // but yaha hum bade graph store karwa sakte hai jo hum matrix nahi karwa payenge
    for(pair<int, int> child: graph2[i]){
        if(child.first == j){
            // connected
            child.second;   // for wt
        }
    }
    return 0;
}



/*
    # Input
6 9
1 3 4
1 5 3
3 5 2
3 4 7
3 6 8
3 2 9
2 6 1
4 6 2 
5 6 3

*/


/*
    -> In Mostly Question, we use adjacency list
*/