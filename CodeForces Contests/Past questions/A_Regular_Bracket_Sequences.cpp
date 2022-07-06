#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<char> c;
        for(int i=0;i<n;i++)
        {
            c.push_back('(');
        }
        for(int i=0;i<n;i++)
        {
            c.push_back(')');
        }
        for(int i=0;i<2*n;i++)
        cout<<c[i];
        cout<<endl;
        int x=n-1,y=c.size()-1;
        while(x>0)
        {
            swap(c[x],c[y-x]);
             for(int i=0;i<2*n;i++)
                 cout<<c[i];
                 cout<<endl;
              swap(c[x],c[y-x]);
              x--;
        }
    } 
    return 0;
}