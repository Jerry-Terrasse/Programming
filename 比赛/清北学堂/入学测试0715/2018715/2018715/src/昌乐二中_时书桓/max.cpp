#include<iostream>
#include<fstream>
using namespace std;

ofstream fout;
ifstream fin;

struct si
{
	int w;
	int h;
};
int l,n,va,vb;
si *a;
void qsort(si*,int,int);
inline void swaps(si &r,si &t)
{
	si v=r;
	r=t;
	t=v;
	return;
}

int main()
{
	//cin>>l>>n>>va>>vb;
	
	fin.open("max.in");
	fout.open("max.out");
	
	fin>>l>>n>>va>>vb;
	
	a=new si[n+1];
	for(int i=1;i<=n;i++)
	 fin>>a[i].h>>a[i].w;
	
	qsort(a,1,n);
	
	int x=1;
	int max=0;
	int t1=0,t2=0;
	int h=0;
	
	for(int i=1;i<=n;i++)
	{
		if(a[i].h>h)
		{
			t1=vb*(a[i].h-h);
			t2=va*(a[i].h-h);
			
			max+=(t2-t1)*a[i].w;
			h=a[i].h;
		}
	}
	
	fout<<max;
	
	fin.close();
	fout.close();
	
	return 0;
}

void qsort(si *x,int st,int ed)
{
	int w=x[st].w;
	int i=st,j=ed;
	if(st>=ed)return;
	while(i!=j)
	{
		while(x[j].w<=w&&j>st)j--;
		while(x[i].w>=w&&i<j)i++;
		swaps(x[i],x[j]);
	}
	swaps(x[st],x[i]);
	qsort(x,st,i-1);
	qsort(x,i+1,ed);
	return;
	
}
