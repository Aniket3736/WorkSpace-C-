#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1e7 + 9
stack<int> s;

void dfs2(vector<vector<int>>& adj,vector<int>& visited,unordered_set<int>& connected,int sv){
    visited[sv] = true;
    connected.insert(sv);
    for(auto i : adj[sv]){
        if(!visited[i]){
            dfs2(adj,visited,connected,i);
        }
    }
}

void dfs(vector<vector<int>>& adj, vector<int>& visited, int sv){
    visited[sv] = true;
    for(auto i : adj[sv]){
        if(!visited[i]){
            dfs(adj,visited,i);
        }
    }
    s.push(sv);
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n),adj2(n);
    vector<int> visited(n,false);
    for(int i = 0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].emplace_back(b-1);
        adj2[b-1].emplace_back(a-1);
    }
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            dfs(adj,visited,i);
        }
    }
    for(int i = 0 ; i<n; i++){
        visited[i] = false;
    }
    unordered_set<int> result;
    while(!s.empty()){
        int sv = s.top();
        s.pop();
        if(!visited[sv]){
            unordered_set<int> connected;
            dfs2(adj2,visited,connected,sv);
            for(auto i : connected){
                for(auto j : adj[i]){
                    if(connected.find(j) == connected.end()){
                        break;
                    }
                    result.insert(i);
                }
                if(adj[i].empty()){
                    result.insert(i);
                }
            }
        }
    }
    for(auto i : result){
        cout<<i+1<<" ";
    }
}
 
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt", "w", stderr);
#endif
// int t;
// cin>>t;
// while(t--)
    solve();
 
return 0;
}