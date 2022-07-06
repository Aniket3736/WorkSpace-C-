#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1e7 + 9

void getpath(vector<int>* adj, int n, vector<int>& path){
    queue<int> q;
    vector<bool> visited(n,false);
    unordered_map<int,int> parent;
    q.push(0);
    parent[0] = 0;
    bool b = false;
    while(!q.empty()){
        int sv = q.front();
        q.pop();
        if(visited[sv])
            continue;
        visited[sv] = true;
        for(auto i : adj[sv]){
            if(!visited[i]){
                parent[i] = sv;
                if(i == n-1){
                    b = true;
                    break;
                }
                q.push(i);
            }
        }
        if(b) break;
    }
    if(!q.empty()){
        int i = n-1;
        while(parent[i] != i){
            path.emplace_back(i);
            i = parent[i];
        }
    }
    reverse(path.begin(), path.end());
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i = 0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].emplace_back(b-1);
        adj[b-1].emplace_back(a-1);
    }
    vector<int> path;
    getpath(adj,n,path);
    cout<<endl;
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