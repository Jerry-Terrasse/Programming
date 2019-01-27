#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<windows.h>
#include<vector>
using namespace std;

int n,k;
struct edge
{
	int right,lift;
	int lengh;
};
edge in[100005];
vector <edge> remain;

edge add(edge r,edge l)
{
	edge sum;
	sum.lift=l.lift;
	sum.right=r.right;
	sum.lengh=sum.right-sum.lift;
	return sum;
}

int main()
{
	scanf("%d%d",&n,&k); 
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&in[i].lift,&in[i].right);
	} 
    int m[n][k];
    memset(m,0,sizeof(m));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(j>=1)
            { 
            	for(int h=0;h<remain.size;h++)
            	{
            		
				}
		//		m[i][j]=max(m[i-1][j],add(in[i-1]));
			}
            else
                m[i][j]=m[i-1][j];
        }
    }
 
 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            cout<<m[i][j]<<' ';
        }
        cout<<endl;
    }

	return 0;
}

