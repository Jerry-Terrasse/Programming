#include<iostream>
#include<algorithm>
using namespace std;
int a[3],g;
int main()
{
  for(int i=0;i<3;i++)
  {
  	cin>>a[i];
	}
	sort(a,a+3);
	g=__gcd(a[0],a[2]);
	a[0]/=g;a[2]/=g;
	cout<<a[0]<<'/'<<a[2]<<endl;
	return 0;
}
