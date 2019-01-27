#include <bits/stdc++.h>
using namespace std;
struct node{
    long long x,c;
}a[100010];
int cmp(node a,node b)
{
    if(a.c==b.c)
        return a.x<b.x;
    return a.c>b.c;
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
    long long l,n,va,vb;
    cin>>l>>n>>va>>vb;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].c;
 
    int t=(va-vb);
    sort(a+1,a+n+1,cmp);
    long long yy=0;
    long long d=0;
    int pp=1;
    yy+=a[1].c*(a[1].x*t);
    for(int i=2;i<=n;i++)
    {
        if(a[i].x>a[pp].x)
        {
            d=a[i].x-a[pp].x;
            yy+=a[i].c*(d*t);
            pp=i;
        }
    }
    cout<<yy<<endl;
    return 0;
}
 
