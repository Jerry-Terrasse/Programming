#include<cstdio>
#include "memory.h"
#define ll long long
#define MAXN 1000010
#define abs(x) (x<0)?(-(x)):(x)
using namespace std;
char p[2],c='\0';
ll st[2][MAXN];
int top[2],cmd=0;
inline void push(const char&,const ll&);
inline void pop(const char&);
inline void add(const char&);
inline void sub(const char&);
inline void del(const char&);
inline void move(const char&);
inline void end(const char&);
inline void out(const bool &);
inline void readc(int&);
void write(const int&);
inline void read(int&);
inline void read(ll&);
int main()
{
	int i=0;
	ll x=0;
	p[0]=0;p[1]=1;
	for(;;)
	{
		readc(cmd);
		switch(cmd)
		{
			case 225806:
				read(i);read(x);
				push(p[i],x);
				break;
			case 31871:
				read(i);
				pop(p[i]);
				break;
			case 26103:
				read(i);
				add(p[i]);
				break;
			case 33096:
				read(i);
				sub(p[i]);
				break;
			case 27237:
				read(i);
				del(p[i]);
				break;
			case 216671:
				read(i);read(i);
				move(p[i]);
				break;
			case 232869:
				p[0]^=1;
				p[1]^=1;
				out(true);
				break;
			case 27965:
				out(true);
				end(p[0]);
				end(p[1]);
				return 0;
			default:
				out(false);
				//write(cmd);
				//putchar('\n');
				break;
		}
	}
	return 0;
}
inline void end(const char &p)
{
	if(top[p])
	{
		for(;top[p];)
	  {
		  write(st[p][top[p]--]);
		  putchar(' ');
	  }
	}
	else
	{
		printf("NONE");
	}
	putchar('\n');
}
inline void move(const char &p)
{
	for(;top[p];)
	{
		st[p^1][++top[p^1]]=st[p][top[p]--];
	}
	out(true);
	return;
}
inline void del(const char &p)
{
	top[p]=0;
	out(true);
	return;
}
inline void sub(const char &p)
{
	if(top[0]&&top[1])
	{
		st[p][top[p]]=abs(st[p][top[p]]-st[p^1][top[p^1]]);
		--top[p^1];
		out(true);
	}
	else
	{
		out(false);
	}
	return;
}
inline void add(const char &p)
{
	if(top[0]&&top[1])
	{
		st[p][top[p]]+=st[p^1][top[p^1]];
		--top[p^1];
		out(true);
	}
	else
	{
		out(false);
	}
	return;
}
inline void pop(const char &p)
{
	if(top[p])
	{
		--top[p];
		out(true);
	}
	else
	{
		out(false);
	}
	return;
}
inline void push(const char &p,const ll &x)
{
	st[p][++top[p]]=x;
	out(true);
	return;
}
inline void out(const bool &bo)
{
	if(bo)
	{
		printf("SUCCESS\n");
	}
	else
	{
		printf("UNSUCCESS\n");
	}
	return;
}
inline void readc(int &x)
{
	for(x=0,c=getchar();c<'A'||c>'Z';c=getchar());
	for(;c>='A'&&c<='Z';c=getchar())
	{
		x+=c;
		x*=7;
	}
	return;
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
inline void read(ll &x)
{
	for(x=0,c=getchar();c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	{
		x=(x<<1)+(x<<3)-'0'+c;
	}
	return;
}
inline void read(int &x)
{
	for(x=0,c=getchar();c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	{
		x=(x<<1)+(x<<3)-'0'+c;
	}
	return;
}
