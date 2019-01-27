#include<iostream>
#include<cstring>                             //头文件
using namespace std;
int n,m,a[201][201],f[201][201]={0},x,y;
int main()
{
    cin>>n>>m;
    y=m/2+1;x=n;                           //求出李大水牛最开始的位置
    memset(a,-9999,sizeof(a));               //设置边界，为了避免李大水牛吃到餐桌外面去。。
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];               //输入
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            f[i][j]=max(max(f[i-1][j],f[i-1][j-1]),f[i-1][j+1])+a[i][j];         //动态方程
        }
    }
    cout<<max(max(f[x][y],f[x][y-1]),f[x][y+1])<<endl;       //因为最大值只可能在李大水牛的前方、左前方、右前方，所以只要找这三个的最大就行了
    for(int i=1;i<=n;++i)
    {
      for(int j=1;j<=m;++j)
      {
        cout<<f[i][j]<<' ';
      }
      cout<<endl;
    }
    return 0;
}