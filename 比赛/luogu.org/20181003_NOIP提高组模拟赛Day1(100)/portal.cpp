#include<iostream>
#define MAXN 110
#define MAXD 8
using namespace std;
int f[MAXD][MAXD],t[MAXN],d[MAXN],c[MAXN],n=0,ans=0;
int main()
{
	int i=1,j=0,x=0,y=0;
	for(cin>>n;i<=n;++i)
	{
		cin>>t[i]>>d[i]>>c[i];
	}
	for(y=0;y<MAXD;++y)
	{
		for(x=0;x<MAXD;++x)
		{
			for(i=1;i<=n;++i)
			{
				for(j=x;j+t[i]<min(d[i],x+y+1);++j)
				{
					f[x][x+y]=max(f[x][x+y],f[x][j]+c[i]+f[j+t[i]][x+y]);
				}
			}
		}
	}
	cout<<f[MAXD-1][MAXD-1]<<endl;
	return 0;
}
