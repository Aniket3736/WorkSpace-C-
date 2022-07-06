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
 

void solve(){
    int n,x; cin>>n>>x;
    string s; cin>>s;
    vector<pair<int,int>> cons0;
    for(int i = 0; i<n;){
        if(s[i] == '0'){
            int count = 0;
            pair<int,int> result;
            result.first = i;
            while(i < n && s[i] == '0') i++,count++;
            result.second = count;
            cons0.push_back(result);
        }
        else i++;
    }
    int result = 0;
    bool b = true;
    for(int i = 0; i<cons0.size(); i++){
        result += cons0[i].second/x;
        if(b && ((cons0[i].first + cons0[i].second) < n)){
            if(((cons0[i].second + 1)/x) > (cons0[i].second/x)) result++,b = false;
        }
        if(b && i < cons0.size()-1){
            if((cons0[i].first + cons0[i].second == cons0[i+1].first - 1) && 
            ((cons0[i].second + cons0[i+1].second + 1)/x) > (cons0[i].second/x + cons0[i+1].second/x))
                result++,b = false;
        }
    }
   cout<<result<<endl;
}
int main()
{
 fast_cin();
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//freopen("error.txt", "w", stderr);
//#endif
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++)
     solve();
 return 0;
}