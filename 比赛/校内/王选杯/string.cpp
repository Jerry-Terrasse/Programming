#include<iostream>
using namespace std;
string a="",b="",c="";
int main()
{
  freopen("toy.in","r",stdin);
  freopen("toy.out","w",stdout);
  int i=0,t=0;
  cin>>a>>b;
  for(;i<a.length();i++)
  {
  	c+=a[i]==b[i]?'0':(t++,(t&1)?a[i]:b[i]);
  }
  if(t&1)
  {
  	cout<<"Impossible"<<endl;
  }
  else
  {
  	cout<<c<<endl;
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
