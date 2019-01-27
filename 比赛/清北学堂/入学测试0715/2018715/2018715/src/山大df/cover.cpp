#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int m,n,k,l,r,t,q;
int f[100000];
struct TYPE
{
	int a,b;
}e[100000];
int cmp(TYPE &x,TYPE &y)
{
	if(x.a!=y.a)return x.b<y.b;
	else return x.a<y.a;
}
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	scanf("%d%d",&e[i].a,&e[i].b);
	sort(e+1,e+1+n,cmp);
	e[0].a=1000001;
	for(int j=n;j>=k;j--)
	{
	     for(int r=l=j-1;l>=r&&q<k;l--)
	     //for(int l=j-1;q>k;l--)
	  {
	     	if(e[j].a<=e[l].b){
		
	     	if(e[l].a<e[0].a)
	  	{
	  		e[0].a=e[l].a;
	  		t=l;
	  		q++;
	  		r--;
		}	 }
		     else continue;
	      }	
		f[j]=e[j].b-e[t].a;
		e[0].a=1000001;
		q=0;
	}
	//for(int i=1;i<=n;i++)cout<<e[i].a<<e[i].b;
  for(int i=n;i>=k+1;i--)
  //cout<<f[i];
  m=max(f[i],f[i-1]);
	cout<<m;
}

