#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1e7 + 9
void solve(){
    int n;
    cin>>n;
    vector<int> sieve(n+1,true);
    sieve[0] = false;
    sieve[1] = false;
    for(int i = 2; i <= sqrt(n); i++){
        if(sieve[i] == false) 
            continue;
        for(int j = i; i*j <= n; j++){
            sieve[i*j] = false;
        }
    }
    for(int i = 0; i<n+1; i++){
        if(sieve[i]){
            cout<<i<<" ";
        }
    }
}
 
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt", "w", stderr);
#endif

// int t;
// cin>>t;
// while(t--)
    solve();
 
return 0;
}