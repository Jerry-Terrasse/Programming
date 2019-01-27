#include<cstdio>
#include<cstring>
#define rg register
#define MAXL 330
#define MAXB 1010
using namespace std;
struct lll
{
	int a[MAXL],l;
	inline lll();
	inline void init();
	inline void input();
	inline void output();
	inline void operator=(const lll*);
	inline void operator+=(const lll&);
	inline void operator*=(const int&);
	inline lll operator*(const int&);
}bas[MAXB],ans;
char ln[MAXB];
int n=0;
inline void init();
int main()
{
	init();
	for(;~scanf("%s",ln);)
	{
		n=strlen(ln);
		ans.init();
		ans.input();
		ans.output();
		putchar('\n');
	}
}
inline void lll::output()
{
	rg int i=0;
	for(i=l+1;--i;)
	{
		putchar(a[i]^48);
	}
	return;
}
inline void lll::input()
{
	rg int i=0;
	for(i=n;i--;)
	{
		if(ln[i]=='1')
		{
			this->operator+=(bas[n-i-1]);
		}
	}
	return;
}
inline void init()
{
	rg int i=0;
	bas[0].a[1]=1;
	for(i=1;i<MAXB;++i)
	{
		bas[i]=bas[i-1]*2;
	}
	return;
}
inline lll lll::operator*(const int &b)
{
	lll ans;
	ans=this;
	ans*=b;
	return ans;
}
inline void lll::operator*=(const int &b)
{
	rg int i=0;
	for(i=1;i<=l;++i)
	{
		a[i]*=b;
	}
	for(i=1;i<=l||a[i];++i)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	l=i-1;
	return;
}
inline void lll::operator+=(const lll &b)
{
	rg int i=0;
	if(l<b.l)
	{
		l=b.l;
	}
	for(i=1;i<=b.l;++i)
	{
		a[i]+=b.a[i];
	}
	for(i=1;i<=l||a[i];++i)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	l=i-1;
	return;
}
inline void lll::operator=(const lll *b)
{
	l=b->l;
	memcpy(a,b->a,sizeof(a));
	return;
}
inline void lll::init()
{
	memset(a,0,sizeof(a));
	l=1;
	return;
}
inline lll::lll()
{
	init();
	return;
}
