#include<iostream>
#include<algorithm>
#define MAXN 500050
#define INF 0x3fffffff
using namespace std;
struct stu
{
  int x,y;
  inline bool operator<(stu b)
  {
    return x<b.x;
  }
}t[MAXN<<1],s[MAXN];
int sim[MAXN],n=0,m=0,cnt=0;
inline bool cmp(stu,stu);
int main()
{
  int i=0,j=0;
  freopen("b.in","r",stdin);freopen("b.out","w",stdout);
  for(cin>>n>>m;i<n;i++)
  {
  	cin>>s[i].x>>s[i].y;
  }
  for(i=0;i<m;i++)
  {
  	cin>>t[i].x>>t[i].y;
  	sim[t[i].x]++;
  }
  sort(t,t+m,cmp);
  for(i=0;i<m;i++)
  {
  	if(sim[t[i].x]>2)
	{
	  for(j=1;j<=sim[t[i].x]-2;j++)
	  {
	  	t[i+j].x=INF;
	  }
	  cnt+=j-1;
	}
  }
  sort(t,t+m,cmp);
  m-=cnt;
  for(i=0;i<n;i++)
  {
  	cnt=-1;
	for(j=0;j<m;j++)
  	{
	  if(cnt<abs(s[i].x-t[j].x)+abs(s[i].y-t[j].y))
  	  {
  	    cnt=abs(s[i].x-t[j].x)+abs(s[i].y-t[j].y);
	  }
	}
	cout<<cnt<<endl;
  }
  fclose(stdin);fclose(stdout);
  return 0;
}
inline bool cmp(stu a,stu b)
{
  return (a.x<b.x)||(a.x==b.x && a.y<b.y);
}
