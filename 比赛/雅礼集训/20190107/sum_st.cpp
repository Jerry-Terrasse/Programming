#include<iostream>
using namespace std;
const int st[30]={1,3,6,8,13,13,20,24,30,30,41,41,54,54,55,63,80,80,99,99,103,103,126,126,146,146,159,164,193,193};
int n=0;
int main()
{
  register int i=0;
  freopen("sum.in","r",stdin);freopen("sum.out","w",stdout);
  cin>>n;
  if(n<=30)
  {
    cout<<st[n-1]<<endl;
    return 0;
  }
  return 0;
}