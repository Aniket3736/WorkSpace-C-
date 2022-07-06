#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1e7 + 9
void solve(){
    int n;
    cin>>n;
    int k = log2(n);
    int sum = 0;
    for(int i = 0; i < k; i++){
        sum += pow(2,i+1);
    }
    sum += (n-pow(2,k))*2;
    cout<<sum;
}
 
int main(){
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// freopen("error.txt", "w", stderr);
// #endif
    solve();
 
return 0;
}