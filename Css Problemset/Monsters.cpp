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
 

string adj[1001];
int visited[1001][1001];
int mindistance[1001][1001];
string result = "";
bool isValid(int i,int j,int n,int m){
    return i >= 0 && j >= 0 && i < n && j < m;
}

void bfs(pair<int,int> input,int n,int m){
    queue<pair<int,int>> q;
    q.push(input);
    while(!q.empty()){
        pair<int,int> temp = q.front();
        q.pop();
        int x = temp.first;
        int y = temp.second;
        for(int k = 0; k<4; k++){
            int dx = x + all4[k][0];
            int dy = y + all4[k][1];
            if(isValid(dx,dy,n,m) && adj[dx][dy] == '.'){
                int data = mindistance[x][y] + 1;
                if(mindistance[dx][dy] > data){
                    mindistance[dx][dy] = data;
                    q.push(make_pair(dx,dy));
                }
            }
        }
    }
}

void dfs(int i,int j,int n,int m,char curr,int dist){
    visited[i][j] = 1;
    if(i == n-1 || i == 0 || j == m-1 || j == 0){
        result += curr;
        return;
    }
    int dx = i+1;
    int dy = j;
    if(isValid(dx,dy,n,m) && !visited[dx][dy] && adj[dx][dy] == '.' && dist+1 < mindistance[dx][dy]){
        dfs(dx,dy,n,m,'D',dist+1);
        if(!result.empty()){
            result += curr;
            return;
        }
    }
    dx = i-1;
    dy = j;
    if(isValid(dx,dy,n,m) && !visited[dx][dy] && adj[dx][dy] == '.' && dist+1 < mindistance[dx][dy]){
        dfs(dx,dy,n,m,'U',dist+1);
        if(!result.empty()){
            result += curr;
            return;
        }
    }
    dx = i;
    dy = j+1;
    if(isValid(dx,dy,n,m) && !visited[dx][dy] && adj[dx][dy] == '.' && dist+1 < mindistance[dx][dy]){
        dfs(dx,dy,n,m,'R',dist+1);
        if(!result.empty()){
            result += curr;
            return;
        }
    }
    dx = i;
    dy = j-1;
    if(isValid(dx,dy,n,m) && !visited[dx][dy] && adj[dx][dy] == '.' && dist+1 < mindistance[dx][dy]){
        dfs(dx,dy,n,m,'L',dist+1);
        if(!result.empty()){
            result += curr;
            return;
        }
    }
    visited[i][j] = 0;
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 0; i<n; i++)   
        cin>>adj[i];
    forn(i,n){
        forn(j,m){
            if(adj[i][j] == 'M') mindistance[i][j] = 0;
            else mindistance[i][j] = INT_MAX;
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0 ; j<m; j++){
            if(adj[i][j] == 'M'){
                bfs(make_pair(i,j),n,m);
            }
        }
    }
    int x = -1,y = -1;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(adj[i][j] == 'A'){
                x = i;
                y = j;
                break;
            }
        }
        if(x != -1) break;
    }
    if(x == -1 || y == -1){
        cout<<"NO";
        return;
    }
    dfs(x,y,n,m,'F',0);
    if(result.empty()){
        cout<<"NO";
        return;
    }
    cout<<"YES"<<endl<<result.size()-1<<endl;
    for(int i = result.size()-2; i >= 0; i--){
        cout<<result[i];
    }
}
int main()
{
 fast_cin();
     solve();
 return 0;
}