#include<iostream>
#include<map>
#define MAXN 300030
using namespace std;
int a[MAXN][2],n=0,ans=0x7fffffff;
map<int,int>m,p;
int main()
{
  int i=0;
  freopen("card.in","r",stdin);freopen("card.out","w",stdout);
  ios::sync_with_stdio(0); 
  for(cin>>n;i<n;i++)
  {
  	cin>>a[i][0]>>a[i][1];
  	m[a[i][0]]++;
  	if(a[i][0]!=a[i][1])
  	{
	  p[a[i][1]]++;
	}
  }
  for(i=0;i<(n<<1);i++)
  {
  	if(m[a[i][0]]+p[a[i][0]]>=((n+1)>>1))
  	{
  	  if(ans>((n+1)>>1)-m[a[i][0]])
  	  {
  	    ans=((n+1)>>1)-m[a[i][0]];
	  }
	}
  }
  if(ans<=0)
  {
  	cout<<0<<endl;
  }
  else if(ans==0x7fffffff)
  {
  	cout<<"Impossible";
  }
  else
  {
  	cout<<ans<<endl;
  }
  fclose(stdin);fclose(stdout);
  return 0;
}
