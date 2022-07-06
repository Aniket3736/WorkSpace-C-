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
 
void merge(vector<int>& input1,int n1, vector<int>& input2, int n2){
    int i = 0, j = 0,k = 0;
    int result[100000];
    while(i < n1 && j < n2){
        if(input1[i] <= input2[j]){
            result[k] = input1[i];
            i++,k++;
        }
        else if(input1[i] > input2[j]){
            result[k] = input2[j];
            j++,k++;
        }
    }
    if(i == n1){
        while(j != n2){
            result[k] = input2[j];
            j++,k++;
        }
    }
    if(j == n2){
        while(i != n1){
            result[k] = input1[i];
            i++,k++;
        }
    }
    if(input1.size())
        input1.clear();
    for(int i = 0; i<k; i++){
        input1.emplace_back(result[i]);
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> input1,result;
    for(int i = 0; i<n; i++){
        if(i == 0){
            int size;
            cin>>size;
            for(int j = 0; j<size; j++){
                int a;
                cin>>a;
                result.emplace_back(a);
            }
        }
        else{
            int size;
            cin>>size;
            for(int j = 0; j<size; j++){
                int a;
                cin>>a;
                input1.emplace_back(a);
            }
            merge(result,result.size(),input1,input1.size());
            input1.clear();
        }
    }
    for(auto i : result){
        cout<<i<<" ";
    }
    cout<<endl;
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