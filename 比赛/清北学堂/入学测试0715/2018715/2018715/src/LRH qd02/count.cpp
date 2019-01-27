#include<cstdio>
#include<cstring>
using namespace std;
bool checkp(char a,char b,char c)
{
	if(a==b&&b==c)return true;
	else return false;
}
bool checkt(char a,char b,char c)
{
	if(a==b&&b!=c)return true;
	if(a==c&&b!=c)return true;
	if(b==c&&a!=c)return true;
	else return false;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n=0,m=0,i,j,k;
	char c[4][4];
	//input
	for(i=1;i<=3;i++)
	scanf("%s",c[i]);
	//players
	if(checkp(c[1][0],c[1][1],c[1][2]))n++;
	if(checkp(c[2][0],c[2][1],c[2][2]))n++;
	if(checkp(c[3][0],c[3][1],c[3][2]))n++;
	if(checkp(c[1][0],c[2][0],c[3][0]))n++;
	if(checkp(c[1][1],c[2][1],c[3][1]))n++;
	if(checkp(c[1][2],c[2][2],c[3][2]))n++;
	if(checkp(c[1][0],c[2][1],c[3][2]))n++;
	if(checkp(c[1][2],c[2][1],c[3][0]))n++;
	//teams
	if(checkt(c[1][0],c[1][1],c[1][2]))m++;
	if(checkt(c[2][0],c[2][1],c[2][2]))m++;
	if(checkt(c[3][0],c[3][1],c[3][2]))m++;
	if(checkt(c[1][0],c[2][0],c[3][0]))m++;
	if(checkt(c[1][1],c[2][1],c[3][1]))m++;
	if(checkt(c[1][2],c[2][2],c[3][2]))m++;
	if(checkt(c[1][0],c[2][1],c[3][2]))m++;
	if(checkt(c[1][2],c[2][1],c[3][0]))m++;
	//output
	printf("%d\n%d\n",n,m);
	fclose(stdin);fclose(stdout);
	return 0;
}
