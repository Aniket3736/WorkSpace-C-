#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1e7 + 9

void dfs(vector<vector<int>>& adj,vector<int>& visited,int sv){
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
    }
    int count = 0;
    vector<int> visited(n,false);
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            count++;
            dfs(adj,visited,i);
        }
    }
    cout<<count<<endl;
}
 
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt", "w", stderr);
#endif

int t;
cin>>t;
while(t--)
    solve();
 
return 0;
}