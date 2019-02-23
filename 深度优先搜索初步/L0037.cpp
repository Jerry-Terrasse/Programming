#include<cstdio>
#include<vector>
#include "memory.h"
using namespace std;
class Solution
{
public:
  bool lin[9][10],col[9][10],squ[9][10],flag;
  int ilin[81],icol[81],isqu[81],a[81];
  inline void init();
  void solveSudoku(vector<vector<char> >&);
  void dfs(const int&);
};
void Solution::dfs(const int &x)
{
  if(x==81)
  {
    flag=true;
    return;
  }
  if(a[x])
  {
    dfs(x+1);
    return;
  }
  register int i=0;
  for(i=1;i<=9;++i)
  {
    if(lin[ilin[x]][i]||col[icol[x]][i]||squ[isqu[x]][i])
    {
      continue;
    }
    a[x]=i;
    lin[ilin[x]][i]=col[icol[x]][i]=squ[isqu[x]][i]=true;
    dfs(x+1);
    if(flag)
    {
      return;
    }
    lin[ilin[x]][i]=col[icol[x]][i]=squ[isqu[x]][i]=false;
    a[x]=0;
  }
  return;
}
void Solution::solveSudoku(vector<vector<char> > &board)
{
  register int i=0,j=0;
  for(i=0;i<9;++i)
  {
    for(j=0;j<9;++j)
    {
      a[i*9+j]=board[i][j];
      if(a[i*9+j]=='.')
      {
        a[i*9+j]=0;
      }
      else
      {
        a[i*9+j]-='0';
      }
    }
  }
  init();
  dfs(0);
  for(i=0;i<9;++i)
  {
    for(j=0;j<9;++j)
    {
      board[i][j]=a[i*9+j]+'0';
    }
  }
  return;
}
inline void Solution::init()
{
  register int i=0,j=0;
  flag=false;
  memset(lin,0,sizeof(lin));
  memset(col,0,sizeof(col));
  memset(squ,0,sizeof(squ));
  for(i=0;i<9;++i)
  {
    for(j=0;j<9;++j)
    {
      ilin[i*9+j]=i;
      icol[i*9+j]=j;
      isqu[i*9+j]=(i/3)*3+j/3;
    }
  }
  for(i=0;i<9;++i)
  {
    for(j=0;j<9;++j)
    {
      if(!a[i*9+j])
      {
        continue;
      }
      lin[i][a[i*9+j]]=true;
      col[j][a[i*9+j]]=true;
      squ[isqu[i*9+j]][a[i*9+j]]=true;
    }
  }
  return;
}
//char ipt[9][9]={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
char ipt[9][9];
vector<vector<char> >a;
int main()
{
  register int i=0,j=0;
  vector<char>x;
  Solution emm;
  for(i=0;i<9;++i)
  {
    scanf("%s",ipt[i]);
  }
  for(i=0;i<9;++i)
  {
    x.push_back(0);
  }
  for(i=0;i<9;++i)
  {
    for(j=0;j<9;++j)
    {
      x[j]=ipt[i][j];
    }
    a.push_back(x);
  }
  emm.solveSudoku(a);
  for(i=0;i<9;++i)
  {
    for(j=0;j<9;++j)
    {
      printf("%c",a[i][j]);
    }
    puts("");
  }
  return 0;
}