#include <bits/stdc++.h> 
 
 
using namespace std;
#define ll long long int
#define pb push_back
#define loop(i,a,n) for(int i=a;i<n;i++)
#define FIO std::ios_base::sync_with_stdio(0); cin.tie(0);
ll mod = pow(10, 9) + 7;
 
 
 
void solve()
{
   int n;
   cin>>n;
   ll result = INT_MAX,ans;
   for(ll i=n+1; ;i++){
      string s = to_string(i);
      auto it = find(s.begin(),s.end(),'8');
      if(it != s.end()){
          ans = i-n;
          break;
      }
   } 
   for(ll i=n-1;i>0 ; i--)
   {
        string s = to_string(i);
        auto it = find(s.begin(),s.end(),'8');
        if(it != s.end()){
            result = min<ll>(ans, n - i);
            break;    
        }
   }
   cout<<ans<<endl;
}
int main()
{
   FIO
      solve();
}