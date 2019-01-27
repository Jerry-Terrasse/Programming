#include <iostream>
#include <algorithm>
using namespace std;
struct sights{
	int xi;
	int ci;
}a[10001];
bool cmp(sights a , sights b)
{
	if (a.ci<b.ci)
	{
	return true;
	}
	else
		if(a.ci==b.ci)
		{
			if(a.xi<b.xi )
			{
				return true ;
			}
		}
	return false ;
}


int main()
{
	int sum,t[10000]={0};
	int flag;
	int L,n,Va,Vb;
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>L>>n>>Va>>Vb;
	for(int i=0;i<n;i++)
	cin>>a[i].xi>>a[i].ci;
	sort(a,a+n,cmp);
	for(int i=n-1;i>=0;i--)
	{
		if(a[i].xi!=0&&a[i].ci!=0)   
		{
			flag=i;
			t[n-i]=Va*a[i].xi-Vb*a[i].xi-t[n-i-1];
			sum+=t[n-i]*a[i].ci;
			for(int i=0;i<n;i++)
			if(a[i].xi<a[flag].xi )
			{
				a[i].ci=0;
				a[i].xi=0;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
