#include<bits/stdc++.h>
using namespace std;
int main()
{
    int bool1=0x7fffffff,bool0=0;
    int N,M,t,i,ans=0;
    char ls[4];
    scanf("%d %d",&N,&M);
    while(N--)
    {
        scanf("%s%d",ls,&t);
        if(*ls=='A')
        {
            bool1&=t;
            bool0&=t;
        }
        else if(*ls=='O')
        {
            bool1|=t;
            bool0|=t;
        }
        else
        {
            bool1^=t;
            bool0^=t;
        }
    }
    cout<<"1:"<<bool1<<endl;
    cout<<"0:"<<bool0<<endl;
    for(i=30;i>=0;i--)
    {
        if(bool0&(1<<i))
        {
            ans+=1<<i;
        }
        else if(M>=(1<<i)&&(bool1&(1<<i)))
        {
            M-=1<<i;
            ans+=1<<i;
        }
    }
    printf("%d",ans);
}
