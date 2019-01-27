#include<iostream>
using namespace std;
//int dg(int);
int a[9],r_A=0,r_B=0,r_C=0;
bool e[10],nok=true;
int dg(int b, const int rA,const int rB,const int rC)
{
  if(b==6)
  {
  	int A=100*a[0]+10*a[1]+a[2],B=100*a[3]+10*a[4]+a[5];
  	if((A*rB)!=(B*rA))
  	{
  	  return 0;
  	}
  }
  if(b==9)
  {
  	int C=100*a[6]+10*a[7]+a[8],B=100*a[3]+10*a[4]+a[5];
  	if((C*rB)==(B*rC))
  	{
  	  int A=100*a[0]+10*a[1]+a[2];
	  cout<<A<<" "<<B<<" "<<C<<endl;
	  nok=false;
	  return 0;
  	}
  }
  for(a[b]=1;a[b]<=9;a[b]++)
  {
  	if(e[a[b]])
  	{
  	  continue;
	}
	else
	{
	  e[a[b]]=true;
	  dg(b+1,rA,rB,rC);
	  e[a[b]]=false;
	}
  }
}
int main()
{
  cin>>r_A>>r_B>>r_C;
  const int rA=r_A,rB=r_B,rC=r_C;
  dg(0,rA,rB,rC);
  //cout<<rA<<rB<<rC;
  if(nok)
  {
  	cout<<"No!!!"<<endl;
  }
  return 0;
}
