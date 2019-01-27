#include<cstdio>
#include<cstring>
#define MAXN 1000000010
using namespace std;
const int p[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int x=0;
bool ok[MAXN];
int main()
{
  int i=0,j=0,k=0;
  bool b=false;
  scanf("%i",&x);
  ok[7]=1;
  for(i=1;p[i]<x;i++)
  {
  	for(j=1;j<=6;j++)
  	{
  	  for(k=0;k<p[i];k++)
  	  {
  	    //printf("%i\n",p[i+1]*j+k);
		ok[p[i]*j+k]=ok[k];
	  }
	}
	for(k=0;k<p[i];k++)
  	{
  	  //printf("%i\n",p[i+1]*j+k);
	  ok[p[i]*7+k]=1;
	}
	for(j=8;j<=9;j++)
	{
	  for(k=0;k<p[i];k++)
  	  {
  	    //printf("%i\n",p[i+1]*j+k);
		ok[p[i]*j+k]=ok[k];
	  }
	}
  }
  for(i=0;i<=x;i+=7)
  {
  	ok[i]=1;
  }
  
  //
  /*for(i=0;i<100;i++)
  {
  	if(ok[i])printf("%i:%i\n",i,ok[i]);
  }*/
  
  for(i=0,j=1;j<x;)
  {
	if(ok[j])
	{
	  //printf("%i:%i\n",j,ok[j]);
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
	//printf("%i",i);
  }
  for(;i<0;i+=1337);
  for(;i>=1337;i-=1337);
  printf("%i",i+1);
  return 0;
}
