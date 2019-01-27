#include<iostream>
using namespace std;
int k;
int main()
{
	int a=0,s[3],c=1;
	cin>>k;
	for(a=10000;a<=30000;a++)
	{
		s[0]=a/100;s[1]=a%10000/10;s[2]=a%1000;
		if(s[0]%k+s[1]%k+s[2]%k==0)
		{
			cout<<a<<endl;
			c=0;
		}
	}
	if(c)
	{
		cout<<"No"<<endl;
	}
	return 0;
}
