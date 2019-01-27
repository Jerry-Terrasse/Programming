#include<iostream>
#include<cstring>
using namespace std;
int p=0,a=0,b=0;
string line[11];
string num[7]=
{
  "xxxxx.....x.xxxxx.xxxxx.x...x.xxxxx.xxxxx.xxxxx.xxxxx.xxxxx.",
  "x...x.....x.....x.....x.x...x.x.....x.........x.x...x.x...x.",
  "x...x.....x.....x.....x.x...x.x.....x.........x.x...x.x...x.",
  "x...x.....x.xxxxx.xxxxx.xxxxx.xxxxx.xxxxx.....x.xxxxx.xxxxx.",
  "x...x.....x.x.........x.....x.....x.x...x.....x.x...x.....x.",
  "x...x.....x.x.........x.....x.....x.x...x.....x.x...x.....x.",
  "xxxxx.....x.xxxxx.xxxxx.....x.xxxxx.xxxxx.....x.xxxxx.xxxxx."
};
inline void geting(int&);
inline char getingchar(int);
inline void puting(int,int,int);
int main()
{
  int i=0;
  for(i=0;i<7;++i)
  {
  	cin>>line[i];
  }
  geting(a);
  geting(b);
  a+=b;
  for(i=0;i<7;++i)
  {
  	puting(a,i,0);
  	putchar('\n');
  }
  return 0;
}
inline void puting(int x,int p,int o)
{
  if(x>9)
  {
  	puting(x/10,p,o+1);
  }
  if(o)
  {
  	cout<<num[p].substr(x%10*6,6);
  }
  else
  {
  	cout<<num[p].substr(x%10*6,5);
  }
}
inline void geting(int &x)
{
  char c='\0';
  for(x=0;p<line[0].length();)
  {
  	c=getingchar(p);
  	p+=6;
  	if(c=='+')
  	{
  	  break;
	}
  	x=(x<<1)+(x<<3)+(c^48);
  }
  return;
}
inline char getingchar(int p)
{
  int i=0;
  string work=line[0].substr(p,5);
  if(work=="xxxxx")
  {
  	work=line[1].substr(p,5);
	if(work=="x...x")
	{
	  work=line[3].substr(p,5);
	  if(work=="x...x")
	  {
	  	return '0';
	  }
	  else
	  {
	  	work=line[4].substr(p,5);
	  	if(work=="x...x")
	  	{
	  	  return '8';
		}
		else
		{
		  return '9';
		}
	  }
	}
	else if(work=="....x")
	{
	  work=line[3].substr(p,5);
	  if(work=="....x")
	  {
	  	return '7';
	  }
	  else
	  {
	  	work=line[4].substr(p,5);
	  	if(work=="x....")
	  	{
	  	  return '2';
		}
		else
		{
		  return '3';
		}
	  }
	}
	else
	{
	  work=line[4].substr(p,5);
	  if(work=="x...x")
	  {
	  	return '6';
	  }
	  else
	  {
	  	return '5';
	  }
	}
  }
  else if(work=="....x")
  {
  	return '1';
  }
  else if(work=="x...x")
  {
  	return '4';
  }
  else
  {
  	return '+';
  }
}
