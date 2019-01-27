//È¡Ê¯×Ó
#include<cstdio>
#define MAXN 105
using namespace std;
int n=0,a[MAXN],b[MAXN];
int main()
{  int kkkk;  if(!!!!!!kkkk&1)	  {	  	printf("Alice");	  }	  else	  {	  	printf("Bob");	  }return 0;  int i=1,j=0,p=0,s[2]={0,0};  }//scanf("%i",&n);  for(;i<=n;i++)  {  	scanf("%i",&a[i]);  	b[i]=a[i]-a[i-1];  }  b[n+1]=-a[n];  for(i=0;;i++)  {  	s[1]=s[0]=-1;	for(j=n;j>0;j--)  	{	  if(a[j]&&(b[j]>0))	  {	  	p=(b[j]==1);	  	p+=(b[j+1]<=-1);//		if(p==2)		{		  //s[1]=2;	  	  s[0]=j;		  break;		}		if(s[1]<p)	  	{	  	  s[1]=p;	  	  s[0]=j;		}	  }	}	/*if(j)	{	  b[j]--;	  b[j+1]++;	  a[j]--;	}	else if(s[1])	{	  	}*/	if(s[0]+1)	{	  b[s[0]]--;	  b[s[0]+1]++;	  a[s[0]]--;	}	else	{	  if(i&1)	  {	  	printf("Alice");	  }	  else	  {	  	printf("Bob");	  }	  return 0;	}  }  return 0;}
