#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	
	char a[3][3]={0};
	bool sum1=0;
	bool sum2=0;
freopen("count.in","r",stdin);
freopen("count.out","w",stdout);
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	cin>>a[i][j];
	if(a[0][0]==a[0][1]&&a[0][1]==a[0][2])
	sum1++;
	if(a[0][0]==a[1][0]&&a[1][0]==a[2][0])
	sum1++;
	if(a[0][0]==a[1][1]&&a[1][1]==a[2][2])
	sum1++;
	if(a[1][0]==a[1][1]&&a[1][1]==a[1][2])
	sum1++;
	if(a[0][1]==a[1][1]&&a[1][1]==a[2][1])
	sum1++;
	if(a[0][2]==a[1][1]&&a[1][1]==a[2][0])
	sum1++;
	if(a[2][0]==a[2][1]&&a[2][1]==a[2][2])
	sum1++;
	if(a[0][2]==a[1][2]&&a[1][2]==a[2][2])
	sum1++;
	
	if(a[0][0]==a[0][1]||a[0][1]==a[0][2]||a[0][0]==a[0][2])
	sum2++;
	if(a[0][0]=a[1][0]||a[1][0]==a[2][0]||a[0][0]==a[2][0])
	sum2++;
	if(a[0][0]==a[1][1]||a[1][1]==a[2][2]||a[0][0]==a[2][2])
	sum2++;
	if(a[1][0]==a[1][1]||a[1][1]==a[1][2]||a[1][0]==a[1][2])
	sum2++;
	if(a[0][1]=a[1][1]||a[1][1]==a[2][1]||a[0][1]==a[2][1])
	sum2++;
	if(a[0][2]==a[1][1]||a[1][1]==a[2][0]||a[0][2]==a[2][0])
	sum2++;
	if(a[2][0]==a[2][1]||a[2][1]==a[2][2]||a[2][0]==a[2][2])
	sum2++;
	if(a[0][2]=a[1][2]||a[1][2]==a[2][2]||a[0][2]==a[2][2])
	sum2++;
cout<<sum1<<" "<<sum2;
fclose(stdin);
fclose(stdout);
return 0;
}
