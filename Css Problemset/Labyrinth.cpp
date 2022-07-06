#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
ll MOD = 1000000007;
int all8[][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
int all4[][2] = {{0,1},{1,0},{-1,0},{0,-1}};
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(long long int t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long int t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

string output; 
bool isValid(int i,int j,int n,int m){
    return i >= 0 && j >= 0 && i < n && j < m; 
}
void dfs(vector<string>& adj,vector<vector<int>>& visited,string result,int i, int j){
    if(adj[i][j] == 'B'){
        if(output.empty()){
            output = result;
            return;
        }
        if(output.size() > result.size()){
            output = result;
        }
        return;
    }
    visited[i][j] = 1;
    int dx = i + 1;
    int dy = j;
    if(isValid(dx,dy,adj.size(),adj[0].size()) && !visited[dx][dy] && adj[dx][dy] != '#'){
        dfs(adj,visited,result+'D',dx,dy);
    }
    dx = i-1;
    dy = j;
    if(isValid(dx,dy,adj.size(),adj[0].size()) && !visited[dx][dy] && adj[dx][dy] != '#'){
        dfs(adj,visited,result+'U',dx,dy);
    }
    dx = i;
    dy = j+1;
    if(isValid(dx,dy,adj.size(),adj[0].size()) && !visited[dx][dy] && adj[dx][dy] != '#'){
        dfs(adj,visited,result+'R',dx,dy);
    }
    dx = i;
    dy = j-1;
    if(isValid(dx,dy,adj.size(),adj[0].size()) && !visited[dx][dy] && adj[dx][dy] != '#'){
        dfs(adj,visited,result+'L',dx,dy);
    }
    visited[i][j] = 0;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> adj;
    for(int i = 0; i<n; i++){
        string s;
        cin>>s;
        adj.push_back(s);
    }
    vector<vector<int>> visited(n,vector<int>(m,0));
    string result = "";
    bool b = false;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(adj[i][j] == 'A'){
                b = true;
                dfs(adj,visited,result,i,j);
                break;
            }
        }
        if(b) break;
    }
    if(output.empty()){
        cout<<"NO";
        return;
    }
    cout<<"YES"<<endl<<output.size()<<endl<<output;
}
int main()
{
 fast_cin();
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//freopen("error.txt", "w", stderr);
//#endif
     solve();
 return 0;
}