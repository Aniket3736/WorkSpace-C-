#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1e7 + 9

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n,vector<int>(n,-1));
    for(int i = 0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a == b && c){
            cout<<"no"<<endl;
            return;
        }
        if(adj[b-1][a-1] != -1 && adj[b-1][a-1] != c){
            cout<<"no"<<endl;
            return;
        }
        adj[a-1][b-1] = c;
    }
    cout<<"yes"<<endl;
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