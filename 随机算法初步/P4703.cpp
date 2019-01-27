#include<iostream>
#include<cstdlib>
#define ld long double
#define MAXN 17
#define dis(xx,yy,i) (sqr(xx-x[i])+sqr(yy-y[i]))
#define sqr(x) ((x)*(x))
using namespace std;
int n=0,l=0;
ld x[MAXN],y[MAXN],t=0,d=0;
int main()
{
  register int i=0;
  register ld xx=0,yy=0,D=0;
  register bool bo=false;
  ios::sync_with_stdio(false);cin.tie(0);
  cin>>n>>l;
  d=(ld)l/n+1e-6;
  d*=d;
  for(i=1;i<=n;++i)
  {
    cin>>x[i]>>y[i];
  }
  for(t=1e7/n;t--;)
  {
    xx=rand()*rand()%l+(ld)rand()/RAND_MAX;
    yy=rand()*rand()%l+(ld)rand()/RAND_MAX;
    if(xx<0||xx>l||yy<0||yy>l)
    {
      continue;
    }
    bo=true;
    for(i=1;i<=n;++i)
    {
      D=dis(xx,yy,i);
      if(D<d)
      {
        bo=false;
        break;
      }
    }
    if(bo)
    {
      cout<<xx<<' '<<yy<<endl;
      return 0;
    }
  }
  cout<<"GG"<<endl;
  return 0;
}