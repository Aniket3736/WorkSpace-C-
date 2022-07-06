#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
while(t--)
{
    long long int n;
    scanf("%lld",&n);
    printf("%lld\n",(n-2)*(n-1)+1);
}
return 0;
}