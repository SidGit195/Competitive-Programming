// InterviewBit Question: https://www.interviewbit.com/problems/delete-edge/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int subtree_sum[N];
int val[N];
const int M = 1e9 + 10;

void dfs(int v, int p=-1){
    subtree_sum[v] += val[v];
    for(int child: g[v]){
        if(child == p) continue;
        dfs(child, v);
        subtree_sum[v] += subtree_sum[child];
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
    long long ans=0;
    for(int i=2; i<=n; ++i){
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1] - subtree_sum[i];
        ans = max(ans, (part1 * 1ll * part2)%M);
    }

    cout << ans << endl;

    return 0;
}



/*
const int M = 1e9 + 10;

void dfs(int v, int p, vector<int> g[], vector<int> &subtree_sum, vector<int> &val){
    subtree_sum[v] += val[v-1];
    for(int child: g[v]){
        if(child == p) continue;
        dfs(child, v, g, subtree_sum, val);
        subtree_sum[v] += subtree_sum[child];
    }
}

//main function
int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    vector<int> g[A.size() + 1];
    vector<int> subtree_sum(A.size() + 1, 0);
    
    for(auto edge: B){
        g[edge[0]].push_back(edge[1]);
        g[edge[1]].push_back(edge[0]);
    }    

    dfs(1, 0, g, subtree_sum, A);
    long long ans=0;
    for(int i=2; i<=A.size(); ++i){
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1] - subtree_sum[i];
        ans = max(ans, (part1 * 1ll * part2)%M);
    }

    return ans;
}

*/