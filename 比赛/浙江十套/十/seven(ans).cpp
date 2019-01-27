#include<iostream>
using namespace std;
int x=0;
inline bool ok(int);
int main()
{
  int i=0,j=1;
  bool b=false;
  //freopen("seven.in","r",stdin);freopen("seven.out","w",stdout);
  for(cin>>x;j<x;)
  {
  	if(ok(j))
  	{
  	  b^=1;
	}
	j++;
	if(b)
	{
	  i--;
	}
	else
	{
	  i++;
	}
	if(i<0)
	{
	  i+=1337;
	}
	if(i>=1337)
	{
	  i-=1337;
	}
  }
  cout<<i+1<<endl;
  //fclose(stdin);fclose(stdout);
  return 0;
}
inline bool ok(int j)
{
  if(j%7==0)
  {
    return true;
  } 
  for(int i=j;i;i/=10)
  {
  	if(i%10==7)
  	{
  	  return true;
	}
  }
  return false;
}
