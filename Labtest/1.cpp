#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1e7 + 9
vector<int> adj[100001];
int visited[100001] = {};

void getDeadusers(int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<adj[i].size(); j++){
            visited[adj[i][j]] = 1;
        }
    }
}

void printUsers(int n){
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i<n; i++){
        pq.push(make_pair(adj[i].size(),i));
    }
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        cout<<p.second<<endl;
    }
}

void solve(){
    int n;
    //cout<<"Enter the number of users"<<endl;
    cin>>n;
    // cout<<"Enter the directed edges :"<<endl;
    for(int i = 0; i<n; i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
    }
    getDeadusers(n); // part a;
    cout<<"Dead users are as follows :"<<endl;
    for(int i = 0; i<n; i++){
        if(!visited[i]) cout<<i<<endl;
    }
    cout<<"Sequence is :"<<endl;
    printUsers(n); //part b;
}
 
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt", "w", stderr);
#endif

    solve();
 
return 0;
}