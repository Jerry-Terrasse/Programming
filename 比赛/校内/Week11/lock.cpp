#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  freopen("lock.in","r",stdin);
  freopen("lock.out","w",stdout);
  int i=0,s=0;
  string a="",b="";
  cin>>i>>a>>b;
  for(i=0;i<a.length();i++)
  {
  	if(a[i]<b[i])
  	{
  	  swap(a[i],b[i]);
	}
	s+=min(a[i]-b[i],b[i]+10-a[i]);
  }
  cout<<s<<endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
