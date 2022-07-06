#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1e7 + 9

void dfs(vector<vector<int>>& adj, vector<bool>& visited, int sv){
    visited[sv] = true;
    for(auto i : adj[sv]){
        if(!visited[i]){
            dfs(adj,visited,i);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i = 0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].emplace_back(b-1);
        adj[b-1].emplace_back(a-1);
    }
    vector<bool> visited(n,false);
    int count = 0;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            count++;
            dfs(adj,visited,i);
        }
    }
    cout<<count;
}
 
int main(){
    solve();
return 0;
}