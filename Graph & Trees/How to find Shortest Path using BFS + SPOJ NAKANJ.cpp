/*
    # Find shortest path using BFS
    when edges do not have any weight or equal weighted edges.
*/

// Practice Question: https://www.spoj.com/problems/NAKANJ/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int vis[8][8];
int level[8][8];

vector<pair<int, int> > movements = {
    {2, 1}, {2, -1},
    {-2, 1}, {-2, -1},
    {1, 2}, {-1, 2},
    {1, -2}, {-1, -2}
};

int getX(string s){
    return s[0] - 'a';
}

int getY(string s){
    return s[1] - '1';
}

bool isValid(int x, int y){
    return x>=0 && y>=0 && x<8 && y<8;
}

int bfs(string source, string dest){
    int sourceX = getX(source);
    int sourceY = getY(source);
    int destX = getX(dest);
    int destY = getY(dest);

    queue<pair<int,int> > q;
    q.push({sourceX, sourceY});
    vis[sourceX][sourceY] = 1;
    level[sourceX][sourceY] = 0;

    while(!q.empty()){
        pair<int,int> cur_v = q.front();
        int x = cur_v.first, y = cur_v.second;
        q.pop();
        
        for(auto movement: movements){
            int childX = movement.first + x;
            int childY = movement.second + y;
            if(!isValid(childX, childY)) continue;
            if(!vis[childX][childY]){
                q.push({childX, childY});
                level[childX][childY] = level[x][y] + 1;
                vis[childX][childY] = 1;
            }
        }
        if(level[destX][destY] != INF){
            break;
        }
    }

    return level[destX][destY]; 
}

void reset(){
    for(int i=0; i<8; ++i){
        for(int j=0; j<8; ++j){
            level[i][j] = INF;
            vis[i][j] = 0;
        }
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        reset();
        string s1, s2;
        cin >> s1 >> s2;
        cout << bfs(s1, s2) << endl;
    }
    return 0;


// BFS is used to find shortest path
// BFS me level wise insertion hote hai
// level 2 hamesha level 3 se phele hi access hoga, zarurri hai (bcz queue hai)
// level is distance from root node