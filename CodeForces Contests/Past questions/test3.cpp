#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,m,pair=0;
        cin>>a>>b>>c>>m;
        pair=a-1+b-1+c-1;
        if(a>b && a>c)
        {
            if(a-(b+c)<=m+1)
            {
                if(pair>=m)
              {
                cout<<"YES"<<endl;
                 }
              else
             {
                 cout<<"NO"<<endl;
                  }
               }
            else
            {
                cout<<"NO"<<endl;
            }

        
        }
        else if(b>c && b>a)
        {
            if(b-(a+c)<=m+1)
            {
                if(pair>=m)
              {
                cout<<"YES"<<endl;
                 }
              else
             {
                 cout<<"NO"<<endl;
                  }
               }
            else
            {
                cout<<"NO"<<endl;
            }
        }
        else
        {
             if(c-(a+b)<=m+1)
            {
                if(pair>=m)
              {
                cout<<"YES"<<endl;
                 }
              else
             {
                 cout<<"NO"<<endl;
                  }
               }
            else
            {
                cout<<"NO"<<endl;
            }
        }
        
       
        
    } 
    return 0;
}