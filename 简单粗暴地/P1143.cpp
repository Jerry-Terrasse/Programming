#include<cstdio>
#define MAXC 255
using namespace std;
int f[MAXC],n=0,a=0,m=0;
char c='\0',g[20];
inline void read(int&);
void write(const int&);
int main()
{
  f['0']=0;f['1']=1;f['2']=2;f['3']=3;f['4']=4;f['5']=5;f['6']=6;f['7']=7;f['8']=8;f['9']=9;
  f['A']=10;f['B']=11;f['C']=12;f['D']=13;f['E']=14;f['F']=15;
  g[0]='0';g[1]='1';g[2]='2';g[3]='3';g[4]='4';g[5]='5';g[6]='6';g[7]='7';g[8]='8';g[9]='9';
	g[10]='A';g[11]='B';g[12]='C';g[13]='D';g[14]='E';g[15]='F';
  scanf("%d",&n);
  read(a);
  scanf("%d",&m);
  write(a);
  putchar('\0');
	return 0;
}
void write(const int &x)
{
	if(x>=m)
	{
		write(x/m);
	}
	putchar(g[x%m]);
	return;
}
inline void read(int &x)
{
  for(x=0;(c<'0'||c>'9')&&(c<'A'||c>'F');c=getchar());
  for(;(c>='0'&&c<='9')||(c>='A'&&c<='F');c=getchar())
  {
  	x=x*n+f[c];
	}
	return;
}
