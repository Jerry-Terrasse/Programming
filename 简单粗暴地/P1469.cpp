#include<cstdio>
using namespace std;
int n=0;
char c='\0';
inline void read(int&);
void write(const int&);
int main()
{
  register int i=0,ans=0;
  read(n);
  for(;n--;read(i),ans^=i);
	write(ans);
	putchar('\n');
	return 0;
}
void write(const int &x)
{
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10^48);
	return;
}
inline void read(int &x)
{
	for(x=0;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	{
		x=(x<<1)+(x<<3)+(c^48);
	}
	return;
}
