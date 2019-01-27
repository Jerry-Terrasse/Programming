#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[12],b[30],t;
int ans1,ans2;
int c[30],cnt;
void iiread()
{
	char c=getchar();
	while(c>'Z'||c<'A')
	 c=getchar();
	while(c>='A'&&c<='Z')
	{
		a[++t]=c-'A'+1;
		c=getchar();
	    if(t>=9) break;
		while(c>'Z'||c<'A')
		 c=getchar();
	}
	return;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	iiread();
	memset(b,0,sizeof(b));
	for(int i=1;i<=3;i++)
	{
		b[a[i]]++;
		if(b[a[i]]==2) 
		{
			if((i==2)&&(a[3]!=a[2]))
			 if((c[a[2]]==c[a[3]]==0)||(c[a[2]]!=c[a[3]]))
			 {
			 ans1++;
			 c[a[2]]=c[a[3]]=++cnt;
			 }
			if(i==3) 
			 if((c[a[1]]==c[a[2]]==c[a[3]]==0)||((c[a[2]]!=c[a[3]])||(c[a[1]]!=c[a[3]])))
			{
				ans1++;
				c[a[1]]=c[a[2]]=c[a[3]]=++cnt;
			}
		}
		if(b[a[i]]==3) ans2++;
	}
	memset(b,0,sizeof(b));
	for(int i=4;i<=6;i++)
	{
		b[a[i]]++;
		if(b[a[i]]==2) 
		{
			if((i==5)&&(a[5]!=a[6]))
			 if((c[a[5]]==c[a[6]]==0)||(c[a[5]]!=c[a[6]]))
			 {
			 ans1++;
			 c[a[6]]=c[a[5]]=++cnt;
			 }
			if(i==6) 
			 if((c[a[4]]==c[a[5]]==c[a[6]]==0)||((c[a[4]]!=c[a[5]])||(c[a[5]]!=c[a[6]])))
			{
				ans1++;
				c[a[4]]=c[a[5]]=c[a[6]]=++cnt;
			}
		}
		if(b[a[i]]==3) ans2++;
	}
	memset(b,0,sizeof(b));
	for(int i=7;i<=9;i++)
	{
		b[a[i]]++;
		if(b[a[i]]==2) 
		{
			if((i==8)&&(a[8]!=a[9]))
			 if((c[a[8]]==c[a[9]]==0)||(c[a[8]]!=c[a[9]]))
			 {
			 ans1++;
			 c[a[8]]=c[a[9]]=++cnt;
			 }
			if(i==9) 
			 if((c[a[7]]==c[a[8]]==c[a[9]]==0)||((c[a[7]]!=c[a[9]])||(c[a[8]]!=c[a[9]])))
			{
				ans1++;
				c[a[7]]=c[a[8]]=c[a[9]]=++cnt;
			}
		}
		if(b[a[i]]==3) ans2++;
	}
	memset(b,0,sizeof(b));
	for(int i=1;i<=7;i+=3)
	{
		b[a[i]]++;
		if(b[a[i]]==2) 
		{
			if((i==4)&&(a[4]!=a[7]))
			 if((c[a[4]]==c[a[7]]==0)||(c[a[4]]!=c[a[7]]))
			 {
			 ans1++;
			 c[a[4]]=c[a[7]]=++cnt;
			 }
			if(i==7) 
			 if((c[a[1]]==c[a[4]]==c[a[7]]==0)||((c[a[1]]!=c[a[7]])||(c[a[4]]!=c[a[7]])))
			{
				ans1++;
				c[a[7]]=c[a[4]]=c[a[1]]=++cnt;
			}
		}
		if(b[a[i]]==3) ans2++;
	}
	 memset(b,0,sizeof(b));
	for(int i=2;i<=8;i+=3)
	{
		b[a[i]]++;
		if(b[a[i]]==2) 
		{
			if((i==5)&&(a[5]!=a[8]))
			 if((c[a[8]]==c[a[5]]==0)||(c[a[8]]!=c[a[5]]))
			 {
			 ans1++;
			 c[a[8]]=c[a[5]]=++cnt;
			 }
			if(i==8) 
			 if((c[a[2]]==c[a[8]]==c[a[5]]==0)||((c[a[2]]!=c[a[8]])||(c[a[8]]!=c[a[5]])))
			{
				ans1++;
				c[a[2]]=c[a[8]]=c[a[5]]=++cnt;
			}
		}
		if(b[a[i]]==3) ans2++;
	}
		memset(b,0,sizeof(b));
	for(int i=3;i<=9;i+=3)
	{
		b[a[i]]++;
		if(b[a[i]]==2) 
		{
			if((i==6)&&(a[6]!=a[9]))
			 if((c[a[6]]==c[a[9]]==0)||(c[a[6]]!=c[a[9]]))
			 {
			 ans1++;
			 c[a[6]]=c[a[9]]=++cnt;
			 }
			if(i==9) 
			 if((c[a[3]]==c[a[6]]==c[a[9]]==0)||((c[a[3]]!=c[a[9]])||(c[a[6]]!=c[a[9]])))
			{
				ans1++;
				c[a[3]]=c[a[6]]=c[a[9]]=++cnt;
			}
		}
		if(b[a[i]]==3) ans2++;
	}
		memset(b,0,sizeof(b));
	for(int i=1;i<=9;i+=4)
	{
		b[a[i]]++;
		if(b[a[i]]==2) 
		{
			if((i==5)&&(a[5]!=a[9]))
			 if((c[a[5]]==c[a[9]]==0)||(c[a[5]]!=c[a[9]]))
			 {
			 ans1++;
			 c[a[5]]=c[a[9]]=++cnt;
			 }
			if(i==9) 
			 if((c[a[1]]==c[a[5]]==c[a[9]]==0)||((c[a[1]]!=c[a[9]])||(c[a[5]]!=c[a[9]])))
			{
				ans1++;
				c[a[1]]=c[a[5]]=c[a[9]]=++cnt;
			}
		}
		if(b[a[i]]==3) ans2++;
	}
		memset(b,0,sizeof(b));
	for(int i=3;i<=7;i+=2)
	{
		b[a[i]]++;
		if(b[a[i]]==2) 
		{
			if((i==5)&&(a[5]!=a[7]))
			 if((c[a[5]]==c[a[7]]==0)||(c[a[5]]!=c[a[7]]))
			 {
			 ans1++;
			 c[a[5]]=c[a[7]]=++cnt;
			 }
			if(i==7) 
			 if((c[a[7]]==c[a[5]]==c[a[3]]==0)||((c[a[7]]!=c[a[3]])||(c[a[5]]!=c[a[7]])))
			{
				ans1++;
				c[a[7]]=c[a[3]]=c[a[5]]=++cnt;
			}
		}
		if(b[a[i]]==3) ans2++;
	}
	printf("%d\n%d\n",ans2,ans1);
	return 0;
}
