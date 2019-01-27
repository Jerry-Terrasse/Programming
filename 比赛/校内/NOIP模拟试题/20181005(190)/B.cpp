#include<queue>
#include<cstdio>
#define _ 0
using namespace std;
int n=0,m=0;
char c='\0';
priority_queue<int,vector<int>,greater<int> >q;
inline void read(int&);
void write(const int&);
int main()
{
  int i=0,x=0,y=0;
  for(read(n),read(m);n--;)
  {
  	read(i);
  	q.push(i);
  }
  for(i=0;m--;i++)
  {
	x=q.top();
  	q.pop();
  	if(x==i&&q.top()==i)
  	{
  	  q.push(x);
  	  break;
	}
  	q.push(x+1);
  }
  write(q.top());
  putchar('\n');
  return ~~(0^_^0);
}
void write(const int &x)
{
  if(x>9)
  {
  	write(x/10);
  }
  putchar(x%10+'0');
  return;
}
inline void read(int &x)
{
  for(x=0;c<'0'||c>'9';c=getchar());
  for(;c>='0'&&c<='9';c=getchar())
  {
  	x=(x<<1)+(x<<3)-'0'+c;
  }
  return;
}
