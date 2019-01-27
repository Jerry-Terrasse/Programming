#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
void input();
void work();
void output(int);
short a[2][10001];
int la[2]={0,0};
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
  int j=0;
  for(int i=0;i<=1;i++)
  {
  	j=1;
  	string inp="";
  	cin>>inp;
  	int k=0;
    for(c=inp[k];(k<=inp.length()-1)&&(c!='\n')&&(c!='\r');k++,c=inp[k])
    {
      a[i][j]=c-'0';
      j++;
    }
    j--;
    la[i]=j;
  }
}
void work()
{
  int i=0,j=0;
  for(i=la[1],j=la[0];i>0;i--,j--)
  {
  	a[0][j]+=a[1][i];
  	a[0][j-1]+=(int)a[0][j]/10;
  	a[0][j]%=10;
  }
  for(;j>0;j--)
  {
  	a[0][j-1]+=(int)a[0][j]/10;
  	a[0][j]%=10;
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
