//P1089 of Luogu
#include<iostream>
using namespace std;
int main()
{
 int s=0,m=0,i;
 for(i=1;i<=12;i++)
 {
   int a=0;
   cin>>a;
   s+=300;
   s-=a;
   if(s<0)
   {
   	cout<<"-"<<i<<endl;
   	return 0;
   }
   else
   {
   	m+=s/100;
   	s%=100;
   }
 }
 s+=(m*120);
 cout<<s<<endl;
 return 0;
}
