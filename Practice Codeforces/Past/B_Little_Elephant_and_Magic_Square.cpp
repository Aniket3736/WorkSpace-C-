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
 
 bool check(int arr[][3]){
    int row[3] = {0}, column[3] = {0}, diag1 = 0, diag2 = 0;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            row[i] += arr[i][j];
            column[i] += arr[j][i];
        }
    }
    diag1 = arr[0][0] + arr[1][1] + arr[2][2];
    diag2 = arr[0][2] + arr[1][1] + arr[2][0];
    sort(row,row+3);
    sort(column,column+3);
    if(row[0] != row[2] || row[2] != column[2] || column[0] != column[2] || row[2] != diag1 || row[2] != diag2) return false;
    return true;
 }

 void print(int arr[][3]){
     for(int i = 0; i<3; i++){
         for(int j = 0; j<3; j++) cout<<arr[i][j]<<" ";
         cout<<endl;
     }
 }

void solve(){
    int arr[3][3];
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++) cin>>arr[i][j];
    }
    arr[0][0] = (2*arr[0][2] + arr[1][2] - arr[1][0])/2;
    arr[2][2] = arr[2][0] + (arr[1][0] - arr[1][2])/2;
    arr[1][1] = arr[0][0] + arr[0][1] + arr[0][2] - arr[1][0] - arr[1][2];
    print(arr);
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