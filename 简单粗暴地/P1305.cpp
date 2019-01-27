#include<iostream>
#define MAXN 32
using namespace std;
struct node
{
  int son=-1,daughter=-1;
}tr[MAXN<<2];
int bo[MAXN],head[MAXN],n=0,root=0,cnt=0;
char s[3];
void dfs(const int&);
int main()
{
  int i=0;
  cin>>n;
  for(i=1;i<=n;++i)
  {
  	cin>>s;
  	bo[s[1]-'a']=bo[s[2]-'a']=1;
  	if(s[1]!='*')
  	{
  	  tr[s[0]-'a'].son=s[1]-'a';
	}
  	if(s[2]!='*')
  	{
  	  tr[s[0]-'a'].daughter=s[2]-'a';
	}
  }
  for(root=0;root<MAXN;++root)
  {
  	if(!bo[root])
  	{
  	  break;
	}
  }
  dfs(root);
  return 0;
}
void dfs(const int &x)
{
  cout<<(char)(x+'a');
  if(tr[x].son!=-1)
  {
  	dfs(tr[x].son);
  }
  if(tr[x].daughter!=-1)
  {
    dfs(tr[x].daughter);
  }
  return;
}
