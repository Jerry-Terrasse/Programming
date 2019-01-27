#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define MAXN 100010
using namespace std;
int a[MAXN],n=0;
ofstream fout;
ifstream fin;
inline void work();
int main()
{
  register int i=0,j=0,ret=0;
  system("sort_da.exe >sort.in");
  fin.open("sort.in");
  fin>>n;
  for(i=1;i<=n;++i)
  {
    fin>>a[i];
  }
  fin.close();
  fout.open("sort_test.ans");
  work();
  for(i=0;;++i)
  {
    cout<<i<<endl;
    random_shuffle(a+1,a+n+1);
    fout.open("sort_test.out");
    work();
    if(system("fc sort_test.out sort_test.ans"))
    {
      system("pause");
    }
    else
    {
      cout<<"the same"<<endl;
    }
  }
  return 0;
}
inline void work()
{
  register int i=0,j=0,ret=0;
  for(i=1;i<=100;++i)
  {
    ret=i;
    for(j=1;j<=n;++j)
    {
      ret%=a[j];
    }
    fout<<ret<<endl;
  }
  fout.close();
  return;
}