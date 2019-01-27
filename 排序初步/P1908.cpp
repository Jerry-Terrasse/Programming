#include<iostream>
#define MAXN 40010
using namespace std;
void ms(int,int);
int n=0,a[MAXN],b[MAXN],ans=0;
int main()
{
  int i=0;
  for(cin>>n;i<n;i++)
  {
  	cin>>a[i];
  }
  ms(0,n-1);
  cout<<ans<<endl;
  /*for(int kk=0;kk<n;kk++)
  {
    cout<<a[kk]<<' ';
  }*/
  return 0;
}
void ms(int l,int r)
{
  /*cout<<l<<","<<r<<":";
  for(int kk=0;kk<n;kk++)
  {
    cout<<a[kk]<<' ';
  }
  cout<<endl;*/
  if(r-l<=1)
  {
  	if(a[l]>a[r])
  	{
  	  ans++;
  	  swap(a[l],a[r]);
	}
	return;
  }
  int mid=(l+r)>>1;
  ms(l,mid);ms(mid+1,r);
  int i=l,j=mid+1,k=0;
  for(;i<=mid && j<=r;)
  {
  	if(a[i]<=a[j])
  	{
  	  b[k++]=a[i++];
	}
	else
	{
	  b[k++]=a[j++];
	  ans+=mid+1-i;
	}
  }
  for(;i<=mid;b[k++]=a[i++]);
  for(;j<=r;b[k++]=a[j++]);
  for(i=l,j=0;i<=r;a[i++]=b[j++]);
  return;
}
