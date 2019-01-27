#include<cstdio>
#include<algorithm>
using namespace std;
char a[5][5];
int n=0,m=0;
char xiaodui(char a,char b,char c)
{
	if(a==b&&b!=c) m++;
	if(a==c&&a!=b) m++;
	if(b==c&&b!=a) m++;
	if(a==b&&b==c) n++;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int i,j;
	char ct;
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
		   ct=getchar();
		   a[i][j]=ct;		
		}
		getchar();
	}
    xiaodui(a[1][1],a[1][2],a[1][3]);
    xiaodui(a[1][1],a[2][1],a[3][1]);
    xiaodui(a[2][1],a[2][2],a[2][3]); 
    xiaodui(a[1][2],a[2][2],a[3][2]); 
    xiaodui(a[3][1],a[3][2],a[3][3]); 
    xiaodui(a[1][3],a[2][3],a[3][3]);
    xiaodui(a[1][1],a[2][2],a[3][3]); 
    xiaodui(a[3][1],a[2][2],a[1][3]); 
    printf("%d\n%d",n,m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
