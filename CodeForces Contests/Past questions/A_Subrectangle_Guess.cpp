#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1e7 + 9
int vec[41][41];
bool watch2(int a,int b, int startRow, int startColumn, int greatest){
    for(int i = startRow; i<startRow + a; i++){
        for(int j = startColumn; j<startColumn + b; j++){
            if(vec[i][j] == greatest) return true;
        }
    }
    return false;
}

bool watch(int a,int b,int greatest, int n, int m){
    for(int i = 0; i<n-a+1; i++){
        for(int j = 0; j<m-b+1; j++){
            if(!watch2(a,b,i,j,greatest)) return false;
        }
    }
    return true;
}

void solve(){
    int n,m; cin>>n>>m;
    int greatest = INT_MIN, count = 0; 
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++)
            cin>>vec[i][j], greatest = max(greatest,vec[i][j]);
    }
    for(int i = 1; i<=n; i++){
        bool check = false;
        for(int j = 1; j<=m; j++){
            if(watch(i,j,greatest,n,m)){
                cout<<i*j<<endl;
                check = true;
                break;
            }
        }
        if(check) break;
    }
}
 
int main(){
int t;
cin>>t;
while(t--)
    solve();
 
return 0;
}