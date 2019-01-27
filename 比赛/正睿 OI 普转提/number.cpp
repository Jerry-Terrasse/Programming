#include<iostream>
#include<bitset>
#include<vector>
#define MAXP 0x7fffffff
#define MAXK 110
using namespace std;
int p[MAXK],n=0,k=0,m=0,cnt=0;
bitset<MAXP>ak;
int main()
{
  freopen("number.in","r",stdin);freopen("number.out","w",stdout);
  int i=0,j=0;
  bool bo=false;
  vector<int>::iterator it;
  ios::sync_with_stdio(0);
  cin>>k>>n;
  for(;i<k;i++)
  {
  	cin>>p[i];
  	ak[p[i]]=1;
  }
  for(i=2;cnt<n;i++)
  {
  	if(ak[i])
  	{
  	  cnt++;
  	  //cout<<i<<endl;
  	  for(j=0;j<k && p[j]*i<MAXP;j++)
  	  {
  	    ak[p[j]*i]=1;
	  }
	}
  }
  cout<<i-1<<endl;
  fclose(stdin);fclose(stdout);
  return 0;
}
