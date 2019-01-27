#include<iostream>
using namespace std;
int main()
{
  int i,k=0;
  double s=0;
  cin>>k;
  for(i=1;s<=k;i++)
  {
  	s=(double)1/i+s;
  }
  cout<<i-1<<endl;
  return 0;
}
