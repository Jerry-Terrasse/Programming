#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long n=0,a[100000],kkkk=0;
void so(long,long);
int main()
{
  freopen("P1177.in","r",stdin);
  long i=0;
  scanf("%i",&n);
  //n=9000;
  for(i=0;i<n;i++)
  {
  	scanf("%i",&a[i]);
  }
  so(0,n-1);
  //so(999,999);
  for(i=0;i<n;i++)
  {
  	printf("%i ",a[i]);
  }
  printf("\n");
  fclose(stdin);
  return 0;
}
void so(long l,long r)
{
  if(l>=r)
    return;
  long i=l,j=r,v=a[l];
  for(;i<j;)
  {
  	for(;(a[j]>=v)&&(i<j);j--);
  	swap(a[i],a[j]);
  	/*if(i<j)
  	{
  	  a[i]=a[j];
  	  i++;
	}*/
  	for(;(a[i]<=v)&&(i<j);i++);
  	/*if(i<j)
  	{
  	  a[j]=a[i];
  	  j--;
	}*/
	swap(a[i],a[j]);
  	//a[i]=v;
  	//return;
  }
  if(l!=max(i-1,l))
  {
    //cout<<"A:"<<l<<","<<max(i-1,l)<<endl;
    so(l,max(i-1,l));
  }
  if(min(r,i+1)!=r)
  {
    //cout<<"B:"<<min(r,i+1)<<","<<r<<endl;
    so(min(r,i+1),r);
  }
  /*so(l,i-1);
  so(i+1,r);*/
  return;
}
/*void so(int x,int y)
    {
        int i=x,j=y;
        int k=a[x];
        if(i>=j)
            return;
        while(i<j)
        {
            while(i<j&&a[j]>k)
                j--;
            if(i<j)
            {
                a[i]=a[j];
                i++;
            }
            while(i<j&&a[i]<=k)
                i++;
            if(i<j)
            {
                a[j]=a[i];
                j--;
            }
        }
        a[i]=k;
        so(x,i-1);
        so(i+1,y);
    }*/
