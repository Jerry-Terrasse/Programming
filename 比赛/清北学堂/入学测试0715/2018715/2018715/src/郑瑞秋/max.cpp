#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define M 101000

struct Node{
	int h,c;
}node[M];
int L,n,Va,Vb,ans;

bool cmp(Node a,Node b)
{
	if(a.h!=b.h)return a.h<b.h;
		return a.c>b.c;
}

int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>L>>n>>Va>>Vb;
	for(int h,c,i=1;i<=n;i++)
	{
		cin>>h>>c;
		node[i]=(Node){h,c};
	}
	sort(node+1,node+n+1,cmp);
	//for(int i=1;i<=n;i++)cout<<node[i].h<<" "<<node[i].c<<endl;
	for(int i=1;i<=n;i++)
	{
		ans+=((node[i].h-node[i-1].h)*(Va-Vb)*node[i].c);
	}
	cout<<ans;
}
