#include<iostream>
#include<iomanip>
#define MAXN 110
#define ld long double
using namespace std;
struct ex_mat
{
  ld a[MAXN][MAXN];
  inline void input();
  inline void output();
  inline void work();
  inline void exchange(int,int);
  inline void add(int,int,ld);
  inline void output(int);
  inline void check();
}eql;
int n=0;
inline bool eqal(ld,ld);
int main()
{
  eql.input();//eql.check();
  eql.work();
  eql.output();
  return 0;
}
inline void ex_mat::check()
{
  int i=1,j=0;
  for(;i<=n;i++)
  {
  	for(j=1;j<=n;j++)
  	{
  	  cout<<fixed<<setprecision(2)<<a[i][j]<<' ';
	}
	cout<<fixed<<setprecision(2)<<a[i][0]<<endl;
  }
  return;
}
inline bool eqal(ld a,ld b)
{
  return -0.001<a-b && a-b<0.001;
}
inline void ex_mat::work()
{
  int i=1,j=0;
  for(;i<n;i++)
  {
  	if(eqal(a[i][i],0))
  	{
  	  for(j=i+1;j<=n;j++)
  	  {
  	    if(a[j][i])
  	    {
  	      exchange(i,j);
  	      break;
		}
	  }
	}
	if(eqal(a[i][i],0))
	{
	  continue;
	}
	for(j=i+1;j<=n;j++)
	{
	  add(i,j,-a[j][i]/a[i][i]);
	}
  }
  //check();
  for(i=n;i>0;i--)
  {
  	if(eqal(a[i][i],0))
  	{
  	  output(1);
  	  return;
	}
	a[i][0]/=a[i][i];
  	a[i][i]=1;
  	for(j=i-1;j>0;j--)
  	{
  	  add(i,j,-a[j][i]);
	}
	//check();
  }
  //check();
  return;
}
inline void ex_mat::add(int x,int y,ld u)
{
  int i=0;
  for(;i<=n;i++)
  {
  	if(!eqal(a[x][i],0))
  	{
  	  a[y][i]+=a[x][i]*u;
	}
  }
  return;
}
inline void ex_mat::exchange(int x,int y)
{
  int i=0;
  for(;i<=n;i++)
  {
  	swap(a[x][i],a[y][i]);
  }
  return;
}
inline void ex_mat::output()
{
  int i=1;
  for(;i<=n;i++)
  {
  	cout<<fixed<<setprecision(2)<<a[i][0]<<endl;
  }
  return;
}
inline void ex_mat::input()
{
  int i=1,j=0;
  for(cin>>n;i<=n;i++)
  {
  	for(j=1;j<=n;j++)
  	{
  	  cin>>eql.a[i][j];
	}
	cin>>eql.a[i][0];
  }
  return;
}
inline void ex_mat::output(int flag)
{
  cout<<"No Solution"<<endl;
  exit(0);
}
