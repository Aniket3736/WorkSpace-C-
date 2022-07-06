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
 
class Parent{
    public:
    int i,j;
    string s;
    Parent(int i,int j,string s){
        this -> i = i,this -> j = j,this -> s = s;
    }
};

bool isValid(int i,int j,vector<string>& input,int visited[][1001]){
    return 
        i>=0 && j>=0 && 
        i<input.size() && 
        j<input[0].size() && 
        !visited[i][j] && 
        (input[i][j] == '.' || input[i][j] == 'B');
}

string bfs(int i,int j,vector<string>& input,int visited[][1001]){
    queue<Parent*> bfsQ;
    bfsQ.push(new Parent(i,j,""));
    while(!bfsQ.empty()){
        Parent *obj = bfsQ.front();
        bfsQ.pop();
        int i = obj -> i, j = obj -> j;
        string s = obj -> s;
        visited[i][j] = 1;
        if(input[i][j] == 'B') return s;
        if(isValid(i+1,j,input,visited))
            bfsQ.push(new Parent(i+1,j,s+'D'));
        if(isValid(i,j+1,input,visited))
            bfsQ.push(new Parent(i,j+1,s+'R'));
        if(isValid(i-1,j,input,visited))
            bfsQ.push(new Parent(i-1,j,s+'U'));
        if(isValid(i,j-1,input,visited))
            bfsQ.push(new Parent(i,j-1,s+'L'));
    }
    return "";
}

void solve(){
    int n,m; cin>>n>>m;
    vector<string> input;
    int visited[n][1001] = {};
    for(int i = 0; i<n; i++){
        string s;cin>>s;
        input.push_back(s);
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(input[i][j] == 'A'){
                string result = bfs(i,j,input,visited);
                if(result.empty()) cout<<"NO";
                else cout<<"YES\n"<<result.size()<<"\n"<<result;
                return;
            }
        }
    }
}
int main()
{
    fast_cin();
    solve();
    return 0;
}