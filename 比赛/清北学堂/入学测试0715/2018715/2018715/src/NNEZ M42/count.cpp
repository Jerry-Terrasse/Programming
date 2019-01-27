#include <iostream>
#include <cstdio>
using namespace std;
int a[10],pd2[26][26],pd[26],ans1,ans2;
void hh(int s1,int s2,int s3)
{
	if(a[s1]==a[s2]&&a[s2]==a[s3]){pd[a[s1]]=1;return;}
	if(a[s1]==a[s2])pd2[a[s1]][a[s3]]=1,pd2[a[s3]][a[s1]]=1;
	if(a[s1]==a[s3])pd2[a[s1]][a[s2]]=1,pd2[a[s2]][a[s1]]=1;
	if(a[s2]==a[s3])pd2[a[s1]][a[s2]]=1,pd2[a[s2]][a[s1]]=1;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=9;i++)
	{
		char sr;
	    cin>>sr;
	    a[i]=sr-'A';
	}
    hh(1,2,3);hh(4,5,6);hh(7,8,9);
    hh(1,4,7);hh(2,5,8);hh(3,6,9);
    hh(1,5,9);hh(3,5,7);
    for(int i=0;i<=25;i++)if(pd[i])ans1++;
    for(int i=0;i<=25;i++)
    for(int j=i;j<=25;j++)
    {
    	if(pd2[i][j]==1)ans2++;
	}
	printf("%d\n%d",ans1,ans2);
	return 0;
}
