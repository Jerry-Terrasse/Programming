#include<iostream>
#include "memory.h"
using namespace std;
char a[4][4];
bool ak[512];
int ans[2],cnt=0;
int main()
{
  freopen("count.in","r",stdin);freopen("count.out","w",stdout); 
  int i=0,j=0;
  for(;i<3;i++)
  {
  	for(j=0;j<3;j++)
  	{
  	  cin>>a[i][j];
	}
  }
  for(i=0;i<3;i++)
  {
  	memset(ak,0,sizeof(ak));
  	for(j=0;j<3;j++)
  	{
  	  ak[a[i][j]]++;
	}
	for(j=0,cnt=0;j<512;j++)
	{
	  if(ak[j])
	  {
	  	cnt++;
	  }
	}
	if(cnt==1)
	{
	  ans[0]++;
	}
	else if(cnt==2)
	{
	  ans[1]++;
	}
	//
	memset(ak,0,sizeof(ak));
  	for(j=0;j<3;j++)
  	{
  	  ak[a[j][i]]++;
	}
	for(j=0,cnt=0;j<512;j++)
	{
	  if(ak[j])
	  {
	  	cnt++;
	  }
	}
	if(cnt==1)
	{
	  ans[0]++;
	}
	else if(cnt==2)
	{
	  ans[1]++;
	}
  }
  memset(ak,0,sizeof(ak));
  for(i=0;i<3;i++)
  {
  	ak[a[i][i]]++;
  }
  for(j=0,cnt=0;j<512;j++)
  {
  	if(ak[j])
  	{
  	  cnt++;
	}
  }
  if(cnt==1)
  {
    ans[0]++;
  }
  else if(cnt==2)
  {
    ans[1]++;
  }
  memset(ak,0,sizeof(ak));
  for(i=0;i<3;i++)
  {
    ak[a[i][2-i]]++;
  }
  for(j=0,cnt=0;j<512;j++)
  {
    if(ak[j])
  	{
  	  cnt++;
	}
  }
  if(cnt==1)
  {
    ans[0]++;
  }
  else if(cnt==2)
  {
    ans[1]++;
  }
  cout<<ans[0]<<endl;
  cout<<ans[1]<<endl;
  fclose(stdin);fclose(stdout);
  return 0;
}
