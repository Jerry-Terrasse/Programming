#include<iostream>
#include<cstring>
#define MAXN 50010
using namespace std;
string a[MAXN],b[MAXN],s="";
int n=0,m=0,ans=0;
void dg(int,int);
int main()
{
  freopen("sort.in","r",stdin);freopen("sort.out","w",stdout);
  int i=0;
  cin>>n>>m>>s;
  for(;i<n;i++)
  {
  	a[i]=s.substr(i,m);
  }
  dg(0,n-1);
  cout<<ans<<endl;
  return 0;
  fclose(stdin);fclose(stdout);
}
void dg(int l,int r)
{
  if(l+1>=r)
  {
  	if(a[l]>a[r])
  	{
  	  swap(a[l],a[r]);
	  ans++;
	}
	return;
  }
  int mid=(l+r)>>1;
  dg(l,mid);
  dg(mid+1,r);
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
  for(i=l;i<=r;i++)
  {
  	a[i]=b[i];
  }
  return;
}
