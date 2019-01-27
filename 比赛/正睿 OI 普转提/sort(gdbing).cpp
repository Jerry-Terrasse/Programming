#include<iostream>
#include<cstring>
#define MAXN 50010
using namespace std;
string a[MAXN],b[MAXN],s="";
int n=0,m=0,ans=0;
void dg(int,int);
void pt();
void pk(int l,int r)
{
  cout<<"B::";
  for(int kk=l;kk<=r;kk++)cout<<"\""<<b[kk]<<"\",";
  cout<<endl;
  return;
}
int main()
{
  int i=0;
  cin>>n>>m>>s;
  for(;i<n;i++)
  {
  	a[i]=s.substr(i,m);
  	//cout<<"{"<<a[i]<<endl;
  }
  dg(0,n-1);
  pt();
  cout<<ans<<endl;
  //cout<<(int)(a<b)<<endl;
  return 0;
}
void dg(int l,int r)
{
  pt();
  if(l+1>=r)
  {
  	if(a[l]>a[r])
  	{
  	  //swap(a[l],a[r]);
  	  s=a[l];
  	  a[l]=a[r];
  	  a[r]=s;
	  ans++;
	}
	pt();
	return;
  }
  int mid=(l+r)>>1;
  dg(l,mid);
  pt();
  dg(mid+1,r);
  pt();
  int i=l,j=mid+1,k=l;
  for(;i<=mid && j<=r;)
  {
  	if(a[i]>a[j])
  	{
  	  b[k++]=a[j++];
  	  ans+=mid+1-i;
	}
	else
	{
	  b[k++]=a[i++];
	}
  }
  for(;i<=mid;b[k++]=a[i++]);
  for(;j<=r;b[k++]=a[j++]);
  pk(l,r);
  for(i=l;i<=r;i++)
  {
  	a[i]=b[i];
  }
  pt();
  return;
}
void pt()
{
  for(int kk=0;kk<n;kk++)cout<<"\""<<a[kk]<<"\",";
  cout<<endl;
  return;
}
