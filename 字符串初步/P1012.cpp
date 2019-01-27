#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 25
using namespace std;
int n=0;
string a[MAXN];
inline bool cmp(string,string);
int main()
{
  int i=0;
  cin>>n;
  for(;i<n;i++)
  {
  	cin>>a[i];
  }
  sort(a,a+n,cmp);
  for(i=0;i<n;i++)
  {
  	cout<<a[i];
  }
  cout<<endl;
  return 0;
}
inline bool cmp(string a,string b)
{
  return a+b>b+a;
}
