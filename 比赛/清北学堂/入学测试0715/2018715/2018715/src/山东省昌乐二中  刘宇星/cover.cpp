#include <iostream>
#include <algorithm>
using namespace std;

struct line
{
	int l, r;
 
}a[10001];
  int operator1(int x1,int y1)
  {
  	if(x1<=y1)
  	return x1;
  	else return y1;
  }
	int  operator2(int x,int y)
{
		if(x>=y)
		return x;
		else return y;
		}
int main()
{
	int rmin=1000000000;
	int lmax=0;
	int n;
	int m;
int final;
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>a[i].r>>a[i].l;

	for(int i=0;i<n;i++)
	{
	rmin=min(rmin,a[i].r);
    lmax=max(lmax,a[i].l);}


    final=lmax-rmin;
    cout<<final;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
