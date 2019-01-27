#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
const string num[3][21]={{"^","another","first","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~"},{"^","a","both","third","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~","~"},{"^","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"}};
void lower(string&);
int main()
{
  //string s[6]={"","","","","",""};
  string s="";
  int i=0,j=0,k=0,n[6]={0,0,0,0,0,0},m=0;
  for(i=0;i<=5;i++)
  {
  	cin>>s;
	lower(s);
	for(j=0;j<=2;j++)
	{
	  for(k=0;k<=20;k++)
	  {
	    if(num[j][k]==s)
	    {
	      n[m]=k*k%100;
	      m++;
	      goto Xon;
		}
		else if(num[j][k]=="~")
		{
		  goto con;
		}
	  }
	con:;
	}
  Xon:;
  }
  sort(n,n+max(m-1,0));
  cout<<n[0];
  for(i=1;i<=m-1;i++)
  {
  	cout<<setfill('0')<<setw(2)<<n[i];
  }
  cout<<endl;
  return 0;
}
void lower(string & a)
{
  for(int i=0;i<=a.length()-1;i++)
  {
  	if((a[i]>='A')&&(a[i]<='Z'))
  	{
  	  a[i]+='a'-'A';
	}
  }
  return;
}
