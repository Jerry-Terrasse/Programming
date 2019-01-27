#include <iostream>  
#include<stdio.h>  
using namespace std;  
int n,ans,End,map[20];  
void dfs(int row,int ld,int rd,int d)
{
    if(d>n) 
    {
        ans++;
        return;  
    }  
    int pos=End&(~(row|ld|rd|map[d])),p;
    while(pos)
    {  
        p=pos&(-pos);
        pos-=p;  
        dfs(row+p,(ld+p)<<1,(rd+p)>>1,d+1);
    }  
}  
int main()
{  
    char s[20];  
    int i,j,k;  
    scanf("%d\n",&n);  
    End=(1<<n)-1;  
    for(i=1; i<=n; i++)
    {  
        gets(s);  
        for(j=1; j<=n; j++)  
            map[i]=(s[j-1]=='.')+(map[i]<<1);  
    }  
    dfs(0,0,0,1);  
    printf("%d",ans);  
    return 0;  
}  
