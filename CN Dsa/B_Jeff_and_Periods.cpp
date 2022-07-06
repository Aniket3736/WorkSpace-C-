#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1e7 + 9

bool check(vector<int>& input){
    int prev = -1;
    for(int i = 0; i<input.size() - 1; i++){
        if(i == 0){
            prev = input[1] - input[0];
            continue;
        }
        if(input[i+1] - input[i] != prev){
            return false;
        }
    }
    return true;
}

void solve(){
    int n;
    cin>>n;
    map<int,vector<int>> umap;
    for(int i = 0; i<n; i++){
        int a;
        cin>>a;
        umap[a].push_back(i+1);
    }
    for(auto i = umap.begin(); i != umap.end(); i++){
        if(!check(i -> second)){
            umap.erase(i -> first);
            i--;
        }
    }
    if(umap.empty()){
        cout<<0<<endl;
    }
    else cout<<umap.size()<<endl;
    for(auto i : umap){
        if(i.second.size() == 1){
            cout<<i.first<<" "<<0<<endl;
        }
        else{
            cout<<i.first<<" "<<(i.second)[1] - (i.second)[0]<<endl;
        }
    }
    return;
}
 
int main(){
    solve();
 
return 0;
}