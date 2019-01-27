#include<iostream>
using namespace std;
struct line
{
	int rig,lef;
	int ulen;
} l[100010];
int n,k;
struct heap
{
	int value;
	int to;
} h[100010];
int s;
int loc[100010];
int vis[100010];
void sw(int a,int b)
{
	int tmp1,tmp2;
	tmp1=h[a].to;
	tmp2=h[a].value;
	h[a].to=h[b].to;
	h[a].value=h[b].value;
	h[b].to=tmp1;
	h[b].value=tmp2;
	loc[h[a].to]=b;
	loc[h[b].to]=a;
	return;
}
void make(int m)
{
	while(s<m)
	{
		s++;
		int tmp=s;
		while(tmp/2&&h[tmp/2].value<h[tmp].value)
		{
			sw(tmp,tmp/2);
			tmp=tmp/2;
		}
	}
	return;
}
void down(int v)
{
	if(!v||v>s) return;
	int tmp=v;
	if(h[tmp].value<h[2*v].value&&2*v<=s) tmp=2*tmp;
	if(h[tmp].value<h[2*v+1].value&&2*v<=s) tmp=2*tmp+1;
	if(tmp!=v)
	{
		sw(tmp,v);
		down(tmp);
	}
	return;
}
int ex()
{
	int r=h[1].to;
	sw(1,s);
	s--;
	down(1);
	return r;
}
int main()
{
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i].lef>>l[i].rig;
		l[i].ulen=l[i].lef-l[i].rig;
		loc[i]=i;
		h[i].to=i;
		h[i].value=l[i].ulen;
	}
	make(n);
	int ans=0;
	while(k--)
	{
		int tmp=ex();
		ans+=l[tmp].ulen;
		vis[tmp]=1;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			if(l[i].rig<l[tmp].lef||l[i].lef>l[tmp].rig) continue;
			if(l[i].lef<=l[tmp].lef&&l[i].rig>=l[tmp].lef&&l[i].rig<=l[tmp].rig)
			{
				l[i].rig=l[tmp].lef;
				l[i].ulen=l[i].rig-l[i].lef;
				h[loc[i]].value=l[i].ulen;
				down(loc[i]);
			}
			if(l[i].rig>=l[tmp].rig&&l[i].lef<=l[tmp].rig&&l[i].lef>=l[tmp].lef)
			{
				l[i].lef=l[tmp].rig;
				l[i].ulen=l[i].rig-l[i].lef;
				h[loc[i]].value=l[i].ulen;
				down(loc[i]);
			}
			if(l[i].lef<l[tmp].lef&&l[i].rig>l[tmp].rig)
			{
				l[i].ulen-=l[tmp].rig-l[tmp].lef;
				h[loc[i]].value=l[i].ulen;
				down(loc[i]);
			}
			if(l[i].lef>l[tmp].lef&&l[i].rig<l[tmp].rig)
			{
				l[i].lef=l[i].rig;
				l[i].ulen=0;
				h[loc[i]].value=l[i].ulen;
				down(loc[i]);
			}
		}
	}
	cout<<ans;
	return 0;
}
