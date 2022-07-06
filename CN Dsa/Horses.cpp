#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000009
const int all8[][8] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

int factorial(int n){
    if(n <= 1){
        return 1;
    }
    return (1LL*n*factorial(n-1)) % MOD;
}

bool check(int i,int j,vector<vector<int>>& adj){
    return i >= 0 && j >= 0 && i < adj.size() && j < adj[0].size() && adj[i][j];
}

void dfs(vector<vector<int>>& adj,vector<vector<int>>& visited,int& components,int x, int y){
    visited[x][y] = 1;
    components++;
    for(int k = 0; k<8; k++){
        if(check(x+all8[k][0],y+all8[k][1],adj) && !visited[x+all8[k][0]][y+all8[k][1]]){
            dfs(adj,visited,components,x+all8[k][0],y+all8[k][1]);
        }
    }
}

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> adj(n,vector<int>(m,0));
    for(int i = 0; i<q; i++){
        int x,y;
        cin>>x>>y;
        adj[x-1][y-1] = 1;
    }
    vector<vector<int>> visited(n,vector<int>(m,0));
    int result = 1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!visited[i][j] && adj[i][j]){
                int components = 0;
                dfs(adj,visited,components,i,j);
                result = (1LL*factorial(components)*result)%MOD;
            }
        }
    }
    cout<<result<<endl;
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