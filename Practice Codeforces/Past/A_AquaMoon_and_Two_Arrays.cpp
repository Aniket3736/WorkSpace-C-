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
 
int findSmaller(int a[], int b[], int n, int currIndex){
    for(int i = currIndex+1; i<n; i++){
        if(a[i] < b[i]) return i;
    }
    return -1;
}
int findGreater(int a[], int b[], int n, int currIndex){
    for(int i = currIndex+1; i<n; i++){
        if(a[i] > b[i]) return i;
    }
    return -1;
}
void solve(){
    int n; cin>>n;
    int a[n], b[n], sum = 0;
    for(int i = 0; i<n; i++) cin>>a[i], sum += a[i];
    for(int i = 0; i<n; i++) cin>>b[i], sum -= b[i];
    if(sum){
        cout<<-1<<endl;
        return;
    }
    vector<pair<int,int>> result;
    for(int i = 0; i<n; i++){
        if(a[i] == b[i]) continue;
        if(a[i] > b[i]){
            while(a[i] != b[i]){
                int index = findSmaller(a,b,n,i);
                while(a[i] != b[i] && a[index] != b[index]){
                    a[i]--,a[index]++;
                    result.push_back(make_pair(i+1,index+1));
                }
            }
        }
        else{
            while(a[i] != b[i]){
                int index = findGreater(a,b,n,i);
                while(a[i] != b[i] && a[index] != b[index]){
                    a[i]++,a[index]--;
                    result.push_back(make_pair(index+1,i+1));
                }
            }
        }
    }
    cout<<result.size()<<endl;
    for(int i = 0; i<result.size(); i++)
        cout<<result[i].first<<" "<<result[i].second<<endl;
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