#include<cstdio>
#define MAXN 1000010
using namespace std;
int q[MAXN][2],h=1,t=1,n=0,cnt=0,ocnt=0,icnt=0;
char c='\0';
inline void read(int&);
void write(const int&);
int main()
{
  int i=1,x=0;
  freopen("B.in","r",stdin);
  for(read(n);i<=n;++i)
  {
  	for(c=getchar();c<'a'||c>'z';c=getchar());
  	if(c=='s')
  	{
  	  read(x);
  	  ++icnt;
  	  for(++cnt;t>h&&q[t-1][0]>=x;--t);
  	  q[t][0]=x;
  	  q[t][1]=icnt;
  	  ++t;
	}
	else if(c=='m')
	{
	  if(cnt)
	  {
	  	write(q[h][0]);
	  	printf("bug\n");
	  }
	  else
	  {
	  	printf("So happy!no bug!\n");
	  }
	}
	else
	{
	  if(cnt)
	  {
	  	++ocnt;
	  	if(q[h][1]==ocnt)
	  	{
	  	  ++h;
		}
	  	--cnt;
	  }
	  else
	  {
	  	printf("So happy!no bug!\n");
	  }
	}
	for(;c!='\n';c=getchar());
  }
  return 0;
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
