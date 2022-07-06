#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1e7 + 9

class TrieNode{
    public:
    TrieNode *left;
    TrieNode *right;
};

void check(vector<int>& input){
    
}

void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    check(input);
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