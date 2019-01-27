#include<bits/stdc++.h>
using namespace std;
int ji[11];
char ch;
int c;
int co[100];
int fe[10]={0,1,4,7};
int ans,tot;
int use,book,m[4],C,s,t;
int win[100][100];
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=11;i++)
	{
		scanf("%c",&ch);  
		if(65<=ch&&ch<=90) ji[++c]=ch;
	}	
//	for(int i=1;i<=9;i++) printf("%d ",ji[i]);

//横排 
	for(int j=1;j<=3;j++)
	{
		book=0;
		C=0;//
		for(int i=fe[j];i<=fe[j]+2;i++)
		{
			use=ji[i];
			m[++C]=use; //
			co[use]++;
			if(co[use]==3)
			{
				book=1;
				if(win[use][use]!=1)
				{
					win[use][use]=1;
					ans++;		
				}
			} 
			if(co[use]==2) book=2;//0 全都不一样  1  全都一样  2  两个一样的 
		//	if(co[use]==1) m=use;
		//	cout<<co[ji[i]]<<" "<<ji[i]<<endl;
		} 
		if(book==2)
		{
			for(int i=1;i<=3;i++)
			{
				if(co[m[i]]==2) s=m[i];
				if(co[m[i]]==1) t=m[i];
			} 
			if(win[s][t]!=1)
			{
				win[s][t]=1;
				tot++;		
			}
		} 
		for(int i=65;i<=90;i++) co[i]=0;
		for(int i=1;i<=3;i++) m[i]=0;//
		//清零 
	}
	
//竖 
	for(int i=1;i<=3;i++)
	{
		book=0;
		C=0;//
		for(int j=i;j<=i+6;j+=3)
		{
			use=ji[j];
			m[++C]=use; //
			co[use]++;
			if(co[use]==3)
			{
				book=1;
				if(win[use][use]!=1)
				{
					win[use][use]=1;
					ans++;		
				}
			} 
			if(co[use]==2) book=2;
		}
		if(book==2)
		{
			for(int i=1;i<=3;i++)
			{
				if(co[m[i]]==2) s=m[i];
				if(co[m[i]]==1) t=m[i];
			} 
			if(win[s][t]!=1)
			{
				win[s][t]=1;
				tot++;		
			}
		}
		for(int i=65;i<=90;i++) co[i]=0;
		for(int i=1;i<=3;i++) m[i]=0;//	
	}

//对角线1 
	book=0;
	C=0;//
	for(int i=1;i<=9;i+=4)	
	{
		use=ji[i];
		m[++C]=use; //
		co[use]++;
		if(co[use]==3)
		{
			book=1;
			if(win[use][use]!=1)
			{
				win[use][use]=1;
				ans++;		
			}
		} 
		if(co[use]==2) book=2;
	}
	if(book==2)
	{
		for(int i=1;i<=3;i++)
		{
			if(co[m[i]]==2) s=m[i];
			if(co[m[i]]==1) t=m[i];
		} 
		if(win[s][t]!=1)
		{
			win[s][t]=1;
			tot++;		
		}
	}
	for(int i=65;i<=90;i++) co[i]=0;
	for(int i=1;i<=3;i++) m[i]=0;//
		
//对角线2 
	book=0;
	C=0;//
	for(int i=3;i<=7;i+=2)	
	{
		use=ji[i];
		m[++C]=use; //
		co[use]++;
		if(co[use]==3)
		{
			book=1;
			if(win[use][use]!=1)
			{
				win[use][use]=1;
				ans++;		
			}
		} 
		if(co[use]==2) book=2;
	}
	if(book==2)
	{
		for(int i=1;i<=3;i++)
		{
			if(co[m[i]]==2) s=m[i];
			if(co[m[i]]==1) t=m[i];
		} 
		if(win[s][t]!=1)
		{
			win[s][t]=1;
			tot++;	
		}
	}
	
	printf("%d\n%d",ans,tot);
}
