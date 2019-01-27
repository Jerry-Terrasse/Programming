#include<cstdio>
#include<iostream>
using namespace std;
void eat(int,int);
struct cell
{
  int w,c;
}mm[11];
int n=0;
int main()
{
  int t=0,i=0,j=0;
  string s="";
  scanf("10\n");
  for(;t<=9;t++)
  {
    scanf("%i",&n);
  	for(i=1;i<=n;i++)
  	{
  	  scanf("%i ",&mm[i].w);
	  scanf("%s",&s);
  	  mm[i].c=s[0]=='7';
	}
	for(i=1;i<=n;i++)
	{
	  cout<<mm[i].c<<":"<<mm[i].w<<endl;
	}
  }
  return 0;
}
void eat(int a,int b)
{
  if(mm[b].c==mm[a].c)
  {
    mm[a].w+=mm[b].w;
  	for(int i=b;i<n;i++)
  	{
 	  swap(mm[i],mm[i+1]);
    }
    n--;
  }
  else
  {
	if(mm[a].w>=mm[b].w)
	{
	  mm[a].w-=mm[b].w;
	  for(int i=b;i<n;i++)
  	  {
  	    swap(mm[i],mm[i+1]);
	  }
	  n--;
	}
	else
	{
	  mm[b].w-=mm[a].w;
	  for(int i=a;i<n;i++)
  	  {
  	    swap(mm[i],mm[i+1]);
	  }
	  n--;
    }
  }
}
