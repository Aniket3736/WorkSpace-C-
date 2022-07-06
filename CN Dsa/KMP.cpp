#include <bits/stdc++.h>
using namespace std;
 
void createpi(vector<int>& pitable,string s1,int n){
    pitable[0] = 0;
    int i = 1, j = 0;
    while(i < n){
        if(s1[i] == s1[j]){
            pitable[i] = pitable[i-1]+1;
            i++;
            j++;
        }
        else{
            if(j != 0){
                j = pitable[j-1];
            }
            else{
                pitable[i] = 0;
                i++;
            }
        }
    }
}

bool KMP(string s, string s1){
    vector<int> pitable(s1.size());
    createpi(pitable,s1,s1.size());
    int i = 0, j = 0;
    while(i < s.size() && j < s1.size()){
        if(s[i] == s1[j]){
            i++;j++;
        }
        else{
            if(j != 0)
                j = pitable[j-1];
            else i++;
        }
    }
    if(j == s1.size()) return true;
    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    int t;
    cin>>t;
    while(t--){
        string s,s1;
        cin>>s>>s1;
        if(KMP(s,s1)){
            cout<<"Present"<<endl;
        }
        else cout<<"Not Present"<<endl;
    }
    return 0;
}