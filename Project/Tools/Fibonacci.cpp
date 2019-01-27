#include<iostream>
using namespace std;
int main()
{
  int f[2]={1,1},i=0;
  for(i=0;i<=40;i++)
  {
  	cout<<i<<':'<<f[i&1]<<endl;
  	f[i&1]+=f[i&1^1];
	}
	return 0;
}
