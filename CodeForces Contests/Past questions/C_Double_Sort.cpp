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
 
bool compare(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

bool check(pair<int,int> arr[],int n){
    for(int i = 1; i<n; i++){
        if(arr[i].first < arr[i-1].first || arr[i].second < arr[i-1].second)
            return false;
    }
    return true;
}

void solve(){
    int n; cin>>n;
    pair<int,int> arr[n],arr2[n];
    for(int i = 0; i<n; i++) cin>>arr[i].first;
    for(int i = 0; i<n; i++) cin>>arr[i].second;
    for(int i = 0; i<n; i++) arr2[i] = arr[i];
    sort(arr2,arr2+n,compare);
    if(!check(arr2,n)){
        cout<<-1<<endl;
        return;
    }
    vector<pair<int,int>> result;
    for(int i = 0; i<n; i++){
        if(arr2[i] == arr[i]) continue;
        int index = find(arr + i,arr+n,arr2[i]) - arr;
        swap(arr[i],arr[index]);
        result.push_back(make_pair(index + 1,i+1));
    }
    if(result.size() > 10000){
        cout<<-1<<endl;
        return;
    }
    cout<<result.size()<< endl;
    for(int i = 0; i<result.size(); i++)
        cout<<result[i].first<<" "<<result[i].second<<endl;
    // forn(i,n) cout<<arr[i].first<<" ";
    // cout<<endl;
    // forn(i,n) cout<<arr[i].second<<" ";
    // cout<<endl;
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