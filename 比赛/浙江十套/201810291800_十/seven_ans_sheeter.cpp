#include<iostream>
#define MAXX 1000000010
using namespace std;
int x=0;
inline bool ok(int);
int main()
{
  register int i=0,j=1;
  register bool b=false;
  //freopen("seven.in","r",stdin);freopen("seven.out","w",stdout);
  for(;j<MAXX;)
  {
  	if(ok(j))
  	{
  	  b^=1;
	}
	++j;
	if(b)
	{
	  --i;
	}
	else
	{
	  ++i;
	}
	if(i<0)
	{
	  i+=1337;
	}
	else if(i>=1337)
	{
	  i-=1337;
	}
	if(!(j%10000000))
	{
	  cout<<(int)b<<',';
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
