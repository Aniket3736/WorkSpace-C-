#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1e7 + 9

void dfs(vector<vector<int>>& adj,vector<bool>& visited,unordered_set<int>& components,int sv){
    visited[sv] = true;
    components.insert(sv);
    for(auto i : adj[sv]){
        if(!visited[i]){
            dfs(adj,visited,components,i);
        }
    }
}

int getAnswer(vector<int>& input,unordered_set<int>& components){
    int result = 0;
    for(auto i : components){
        result += input[i];
    }
    return result;
}


void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<bool> visited(n,false);
    vector<int> input(n);
    int maxm = 0;
    for(int i = 0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].emplace_back(b-1);
        adj[b-1].emplace_back(a-1);
    }
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            unordered_set<int> components;
            dfs(adj,visited,components,i);
            maxm = max(maxm,getAnswer(input,components));
        }
    }
    cout<<maxm<<endl;
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