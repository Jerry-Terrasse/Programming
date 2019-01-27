#include<iostream>
#include<queue>
#include<vector>
#include<fstream>
using namespace std;
ifstream fin("max.in");
ofstream fout("max.out");
int L,n,va,vb;
struct tHeap
{
    long long x,c;
    bool operator < (const tHeap &k) const
    {
        return c<k.c;
    };
};
long long high,last;
long long ans;
priority_queue <tHeap> s;
int main()
{
	fin>>L>>n>>va>>vb;
	for(int i=1;i<=n;i++)
	{
		tHeap t;
		fin>>t.x>>t.c;
		s.push(t);
	}
	while(!s.empty())
	{
		tHeap t=s.top();
		while(t.x<high) 
		{
			s.pop();
			if(s.empty()) break;
			t=s.top();
		}
		s.pop();
		ans+=(va-vb)*(t.x-high)*t.c;
		last=high;
		high=t.x;
	}
	fout<<ans;
	return 0;
}
