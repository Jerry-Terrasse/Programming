#include<iostream>
#include<queue>
#include<vector>
#include<fstream>
#include<cstring>
using namespace std;
ifstream fin("cover.in");
ofstream fout("cover.out");
int n,k;
int ans;
struct tHeap
{
    int l,r,len;
    bool operator < (const tHeap &k) const
    {
        return len<k.len;
    };
};
priority_queue <tHeap> s;
int main()
{
	fin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		tHeap t;
		fin>>t.l>>t.r;
		t.len=t.r-t.l;
		s.push(t);
	}
//	fout<<n;
	while(k--)
	{
		tHeap t=s.top();
		s.pop();
		ans+=t.len;
		int i=0;
		tHeap tmp[100005];
		while(!s.empty())
		{
			memset(tmp,0,sizeof(tmp));
			tmp[++i]=s.top();
			s.pop();
			if(tmp[i].l>=t.l&&tmp[i].r<=t.r)
			{
				tmp[i].len=-1234;
			}
			if(tmp[i].l>=t.l&&tmp[i].r>=t.r)
			{
				if(tmp[i].len>tmp[i].r-t.r)
				{
					tmp[i].len=tmp[i].r-t.r;
					tmp[i].l=t.r;
				}
			}
			if(tmp[i].l<=t.l&&tmp[i].r<=t.r)
			{
				if(tmp[i].len>t.l-tmp[i].l)
				{
					tmp[i].len=t.l-tmp[i].l;
					tmp[i].r=t.l;
				}
			}
		}
		for(int j=1;j<=i;j++)
		s.push(tmp[j]);
	}
	fout<<ans;
	return 0;
}
