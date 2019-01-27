#include<cstdio>
#define MAXN 100010
#define max(x,y) x<y?y:x
using namespace std;
int st[MAXN][18],lg[MAXN],n=0,m=0;
char c='\0';
inline void read(int&);
void write(const int&);
int main()
{
  int i=0,j=0,u=0,v=0;
  for(read(n),read(m);(1<<i)<=n;++i)
  {
  	for(j=(1<<i);j<(1<<i+1);++j)
  	{
  		lg[j]=i;
		}
	}
	for(i=1;i<=n;++i)
	{
		read(st[i][0]);
	}
	for(i=1;(1<<i)<=n;++i)
	{
		for(j=1;j+(1<<i)-1<=n;++j)
		{
			st[j][i]=max(st[j][i-1],st[j+(1<<i-1)][i-1]);
		}
	}
	for(;m--;)
	{
		read(u);read(v);
		write(max(st[u][lg[v-u]],st[v-(1<<lg[v-u])+1][lg[v-u]]));
		putchar('\n');
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
