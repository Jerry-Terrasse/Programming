#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#define MAXN 220
using namespace std;
int n=0,hu[MAXN],m=0,use[MAXN],ans=0;
vector<int>anti[MAXN];
map<string,int>no;
string name[MAXN];
int join(string);
void dfs(int);
int main()
{
  freopen("party.in","r",stdin);
  freopen("party.out","w",stdout);
  int i=0,a=0,b=0;
  string s="";
  for(cin>>n;i<n;i++)
  {
  	cin>>s;
  	a=join(s);
  	cin>>hu[a]>>s;
  	b=join(s);
  	anti[a].push_back(a);
  	anti[a].push_back(b);
  	anti[b].push_back(a);
  }
  /*for(i=0;i<m;i++)
  {
  	cout<<name[i]<<' ';
  }
  cout<<endl;*/
  for(i=0;i<m;i++)
  {
  	if(hu[i])
  	{
  	  use[i]=1;
  	  dfs(1);
  	  use[i]=0;
	}
  }
  cout<<ans<<endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
void dfs(int a)
{
  int i=0,j=0,k=0,bo=true;
  if(a==n+1)
  {
  	for(i=0;i<m;i++)
  	{
  	  if(use[i])
  	  {
  	    j+=hu[i];
  	    //cout<<i<<' ';
	  }
	}
	//cout<<endl;
	j>ans?(ans=j):j;
	return;
  }
  for(;i<m;i++)
  {
  	if(use[i] || (!hu[i]))
  	{
  	  continue;
	}
	for(i=0;i<m;i++)
	{
	  bo=true;
	  for(j=0;j<m;j++)
	  {
	  	if(use[j])
	  	{
	  	  for(k=0;k<anti[j].size();k++)
	  	  {
	  	    if(anti[j][k]==i)
	  	    {
	  	      bo=false;
	  	      goto labe;
			}
		  }
		}
	  }
	  labe:;
	  if(bo)
	  {
	  	use[i]=1;
	  	dfs(a+1);
	  	use[i]=0;
	  }
	}
  }
  return;
}
int join(string s)
{
  if(no.count(s))
  {
  	return no[s];
  }
  else
  {
  	no.insert(make_pair(s,m));
  	name[m++]=s;
  	return m-1;
  }
}
