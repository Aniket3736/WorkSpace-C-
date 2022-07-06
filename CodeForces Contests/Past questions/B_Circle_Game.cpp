#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1e7 + 9
void solve(){
    int n; cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    if(n%2){
        cout<<"Mike"<<endl;
        return;
    }
    int minOdd = INT_MAX, minEven = INT_MAX;
    for(int i = 0; i<n; i++){
        if(i%2) minEven = min(minEven,arr[i]);
        else minOdd = min(minOdd,arr[i]);
    }
    if(minEven >= minOdd) cout<<"Joe"<<endl;
    else cout<<"Mike"<<endl;
}
 
int main(){
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//freopen("error.txt", "w", stderr);
//#endif

int t;
cin>>t;
while(t--)
    solve();
 
return 0;
}