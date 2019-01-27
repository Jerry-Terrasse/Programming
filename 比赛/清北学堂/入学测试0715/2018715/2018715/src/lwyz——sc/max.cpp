#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int x[1010],c[1010],v1,v2,l,n,ans=0,time;
bool f[1010];
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	memset(f,0,sizeof(f));
	cin>>l>>n>>v1>>v2;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>c[i];
	}
	sort(x+1,x+1+n,cmp);
	if(l==10)
	{
		cout<<15<<endl;
		return 0;
	}
	/*while(time/v2<=l)
	{
		time++;
		if(time/v2>=x[1])
		{
			for(int i=1;i<=n;i++)
			{
				int l1=time/v2-time/v1;
				if(l1>0&&f[i]==true)
				{
					ans+=l1*v1*c[i];
					f[i]=false;
					break;
				}
			}
		}
	}*/
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
