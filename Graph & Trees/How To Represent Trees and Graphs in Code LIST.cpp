#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;

vector<int> graph[N];

int main(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; ++i){
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    return 0;
}


/*
    # Input
6 9
1 3 
1 5 
3 5 
3 4 
3 6 
3 2 
2 6
4 6 
5 6

*/


/*
     # for adjacency List
    O(N + E) --> space complexity
        
*/