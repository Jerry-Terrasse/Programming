#include<cstdio>
#include<map>
#include<cstring>
#include<iostream>
using namespace std;
const int plusval[11]={0,5,6,7,8,10,12,14,17,20,24};
const int limit[4]={2,3,5,8};
map<string,int>mp;
struct hum
{
  string name,club,country;
  int id,base,exp,plus,ans;
  inline void input(int);
  inline void work();
  inline void output();
}a[16];
int x=0,y=0,z=0,cw=0,cx=0,cy=0,cz=0,scnt=0;
string s[110];
inline void ak();
int main()
{
  int i=0;
  scanf("%d-%d-%d",&x,&y,&z);
  for(i=1;i<=11;i++)
  {
  	a[i].input(i);
  }
  cin>>cw>>cx>>cy>>cz;
  for(i=1;i<=11;i++)
  {
  	a[i].work();
  }
  ak();
  for(i=1;i<=11;i++)
  {
  	a[i].output();
  }
  return 0;
}
inline void hum::output()
{
  cout<<name<<' '<<base+ans<<endl;
  return;
}
inline void ak()
{
  int add[16],dt[110],cnt=0,i=0,j=0;
  memset(add,0,sizeof(add));
  for(i=0;i<4;i++)
  {
  	for(cnt=0,j=1;j<=11;j++)
  	{
  	  if(a[j].plus>=limit[i])
  	  {
  	    cnt++;
	  }
	}
	if(cnt>=6)
	{
	  for(cnt=0,j=1;j<=11;j++)
  	  {
  	    if(a[j].plus>=limit[i])
  	    {
  	      add[j]=max(add[j],i+1);
	    }
	  }
	}
  }
  for(i=1;i<=11;i++)
  {
  	a[i].ans+=add[i];
  }
  memset(add,0,sizeof(add));
  memset(dt,0,sizeof(dt));
  for(i=1;i<=11;i++)
  {
  	dt[mp[a[i].club]]++;
  }
  for(i=0;i<110;i++)
  {
  	if(dt[i]>=6 && dt[i]<=8)
  	{
  	  for(j=1;j<=11;j++)
  	  {
  	    if(a[j].club==s[i] && a[j].plus!=0)
  	    {
  	      add[j]=max(add[j],2);
		}
	  }
	}
	else if(dt[i]>=9 && dt[i]<=10)
	{
	  for(j=1;j<=11;j++)
  	  {
  	    if(a[j].club==s[i] && a[j].plus!=0)
  	    {
  	      add[j]=max(add[j],3);
		}
	  }
	}
  }
  memset(dt,0,sizeof(dt));
  for(i=1;i<=11;i++)
  {
  	dt[mp[a[i].country]]++;
  }
  for(i=0;i<110;i++)
  {
  	if(dt[i]>=6 && dt[i]<=8)
  	{
  	  for(j=1;j<=11;j++)
  	  {
  	    if(a[j].country==s[i] && a[j].plus!=0)
  	    {
  	      add[j]=max(add[j],2);
		}
	  }
	}
	else if(dt[i]>=9 && dt[i]<=10)
	{
	  for(j=1;j<=11;j++)
  	  {
  	    if(a[j].country==s[i] && a[j].plus!=0)
  	    {
  	      add[j]=max(add[j],3);
		}
	  }
	}
  }
  for(i=1;i<=11;i++)
  {
  	a[i].ans+=add[i];
  }
  return;
}
inline void hum::work()
{
  ans=exp-1;
  ans+=plusval[plus];
  if(this->id==1)
  {
  	ans+=cw;
  }
  else if(this->id>=2 && this->id<=2+x-1)
  {
  	ans+=cx;
  }
  else if(this->id>=2+x && this->id<=2+x+y-1)
  {
  	ans+=cy;
  }
  else
  {
  	ans+=cz;
  }
  return;
}
inline void hum::input(int x)
{
  char c='\0';
  ans=0;id=x;
  cin>>name>>base;
  for(;c!='L';c=getchar());
  for(;c!='v';c=getchar());
  for(;c!='.';c=getchar());
  cin>>exp>>plus>>club>>country;
  if(!mp.count(club))
  {
  	s[++scnt]=club;
  	mp.insert(make_pair(club,scnt));
  }
  if(!mp.count(country))
  {
  	s[++scnt]=country;
  	mp.insert(make_pair(country,scnt));
  }
  return;
}
