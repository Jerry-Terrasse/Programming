#include<cstdio>
#define ll long long
#define MAXN 3000030
using namespace std;
ll arc[MAXN],n=0,p=0;
inline ll pow(ll,ll);
void write(const ll&);
int main()
{
  int i=2;
  scanf("%lld%lld",&n,&p);
  for(arc[1]=1;i<=n;i++)
  {
    arc[i]=-(p/i)*arc[p%i];
    arc[i]=(arc[i]%p+p)%p;
  }
  for(i=1;i<=n;i++)
  {
  	write(arc[i]);
  	putchar('\n');
	}
  return 0;
}
void write(const ll &x)
{
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+'0');
	return;
}
