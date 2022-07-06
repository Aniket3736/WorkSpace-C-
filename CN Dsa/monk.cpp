#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1e7 + 9

void getPath(vector<vector<int>>& adj,vector<bool>& visited,vector<int>& path,int n){
    int start = 0;
    bool found = false;
    queue<int> q;
    q.push(start);
    unordered_map<int,int> parent;
    parent[0] = 0;
    while(!q.empty()){
        int sv = q.front();
        q.pop();
        if(visited[sv]) continue;
        visited[sv] = true;
        for(auto i : adj[sv]){
            if(!visited[i]){
                q.push(i);
                parent[i] = sv;
                if(i == n-1){
                    found = true;
                    break;
                }
            }
        }
        if(found){
            break;
        }
    }
    if(found){
        int i = n-1;
        while(parent[i] != i){
            path.emplace_back(i);
            i = parent[i];
        }
        path.emplace_back(i);
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
    vector<int> path;
    vector<bool> visited(n,false);
    getPath(adj,visited,path,n);
    //reverse(path.begin(),path.end());
    // for(auto i : path){
    //     cout<<i<<" ";
    // }
    cout<<path.size()-1<<endl;
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