#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n1 = 7,n2 = 11;
    if(n1 % n2 == 0){
        cout<<n1<<endl;
        return;
    }
    if(n2 % n1 == 0){
        cout<<n2<<endl;
        return;
    }
    int lcm = 1;
    int i = 2;
    while(i <= max(n1,n2)){
        if(n1 == 1){            
            cout<<n2*lcm<<endl;
            return;
        }
        if(n2 == 1){
            cout<<n1*lcm<<endl;
            return;
        }
        if(n1 % i == 0 && n2 % i == 0){
            lcm = lcm*i;
            n1 /= i;
            n2 /= i;
            continue;
        }
        else if(n1 % i == 0){
            lcm = lcm*i;
            n1 /= i;
            continue;
        }
        else if(n2 % i == 0){
            lcm = lcm*i;
            n2 /= i;
            continue;
        }
        i++;
    }
}
 
int main(){
    solve();
return 0;
}