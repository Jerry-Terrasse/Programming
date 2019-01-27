#include<cstdio>
#include<vector>
#include<map>
#define MAXN 500010
using namespace std;
map<int,vector<int> >sd;
int n=0,m=0,x=0,y=0;
bool bo=false;
int main()
{
  int i=0,q=0,j=0;
  char c='\0';
  vector<int> *w=NULL;//work
  scanf("%i%i",&n,&m);
  for(;i<m;i++)
  {
    scanf("%i%i",&x,&y);
    if(sd.count(x))
    {
      sd[x].push_back(y);
	}
	else
	{
	  w=new vector<int>;
	  w->push_back(y);
	  sd.insert(make_pair(x,*w));
	}
	if(sd.count(y))
    {
      sd[y].push_back(x);
	}
	else
	{
	  w=new vector<int>;
	  w->push_back(x);
	  sd.insert(make_pair(y,*w));
	}
  }
  scanf("%i",&q);
  for(i=0;i<q;i++)
  {
  	scanf("\n%c%i%i",&c,&x,&y);
  	if(c=='D')
  	{
  	  w=&sd[x];
	  for(j=0;j<w->size();j++)
	  {
	  	if(*w[j]==y)
	  	{
	  	  w->erase(w->begin()+j);
	  	  break;
		}
	  }
	  w=&sd[y];
	  for(j=0;j<w->size();j++)
	  {
	  	if(*w[j]==x)
	  	{
	  	  w->erase(w->begin()+j);
	  	  break;
		}
	  }
	}
	else
	{
	  bo=false;
	  
	  if(bo)
	  {
	  	printf("C\n");
	  }
	  else
	  {
	  	printf("D\n");
	  }
	}
  }
  return 0;
}
