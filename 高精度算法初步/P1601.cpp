#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
void input();
void work();
void output(int);
long long a[2][30];
int la[2]={0,0};
string s="";
const long long p=pow(10,3);
int main()
{
  input();
  if(la[0]<la[1])
  {
  	swap(la[0],la[1]);
  	swap(a[0],a[1]);
  }
  work();
  output(la[0]);
}
void input()
{
  char c='\0';
  int j=0,k=0,l=0;
  for(int i=0;i<=1;i++)
  {
  	cin>>s;
  	k=s.length();
	l=0;
	for(j=k--/3;k>=0;k--,c=s[k])
    {
	  l++;
	  
	}
	la[i]=j;
  }
}
void work()
{
  int i=0,j=0;
  for(i=la[1],j=la[0];i>0;i--,j--)
  {
  	a[0][j]+=a[1][i];
  	a[0][j-1]+=(int)a[0][j]/p;
  	a[0][j]%=p;
  }
  for(;j>0;j--)
  {
  	a[0][j-1]+=(int)a[0][j]/p;
  	a[0][j]%=p;
  }
}
void output(int i)
{
  int j=0;
  if(a[0][0]!=0)
  {
  	printf("%d",a[0][0]);
  }
  for(j=1;j<=i;j++)
  {
    printf("%d",a[0][j]);
  }
  printf("\n");
}
