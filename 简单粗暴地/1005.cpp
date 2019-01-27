#include<cstdio>
using namespace std;
int main()
{
  int a=0,b=0,x=0,y=0;
  scanf("%d%d%d%d",&x,&a,&y,&b);
  printf("%.2f",(double)(b*y-a*x)/(b-a));
  return 0;
}
