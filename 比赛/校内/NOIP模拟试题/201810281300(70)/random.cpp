#include<iostream>
#include<iomanip>
#define ll long long
#define db double
#define MAXA 5000
using namespace std;
db p=0;
inline bool eql(const db&,const db&);
int main()
{
  register ll i=0,j=0;
  freopen("random.in","r",stdin);freopen("random.out","w",stdout);
  cin>>p;
  for(i=1;;++i)
  {
  	for(j=1;j<i;++j)
  	{
  	  if(eql((db)j/i,p))
  	  {
  	    cout<<fixed<<setprecision(6)<<(db)(j+1)/(i+1)<<endl;
  	    return 0;
	  }
	}
  }
  return 0;
}
inline bool eql(const db &x,const db &y)
{
  return ((x)-(y)>-1e-2&&(x)-(y)<1e-2);
}
