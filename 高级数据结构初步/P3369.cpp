#include<iostream>
#include<cstdlib>
#define MAXN 100010
#define INF 0x7fffffff
using namespace std;
struct node
{
	int val,dat,cnt,size;
	node *son,*daughter;
	inline node();
	inline node(const int&,const int&,const int&);
	void insert(const int&);
	int pre(const int&);
	int next(const int&);
	int gvbr(const int&);
	int grbv(const int&);
}mmp[MAXN],*top,*head;
int main()
{
	int i=0;
	//srand(time(NULL));
	top=mmp;
	head=++top;
	head->val=INF;head->cnt=head->size=1;
	head->insert(-INF);
	return 0;
}
int node::grbv(const int &x)
{
	if(val>x)
	{
		return son->grbv(x);
	}
	if(val==x)
	{
		return son->size+1;
	}
	return son->size+cnt+daughter->grbv(x);
}
int node::gvbr(const int &x)
{
	if(son->size>=x)
	{
		return son->gvbr(x);
	}
	if(son->size+cnt<x)
	{
		return daughter->gvbr(x-son->size-cnt);
	}
	return val;
}
int node::next(const int &x)
{
	if(val>x)
	{
		if(daughter!=mmp)
		{
			return min(val,daughter->next(x));
		}
		else
		{
			return val;
		}
	}
	else
	{
		if(daughter!=mmp)
		{
			return daughter->next(x);
		}
		else
		{
			return INF; 
		}
	}
}
int node::pre(const int &x)
{
	if(val<x)
	{
		if(son!=mmp)
		{
			return max(val,son->pre(x));
		}
		else
		{
			return val;
		}
	}
	else
	{
		if(son!=mmp)
		{
			return son->pre(x);
		}
		else
		{
			return -INF;
		}
	}
}
void node::insert(const int &x)
{
	if(x<val)
	{
		if(son!=mmp)
		{
			son->insert(x);
		}
		else
		{
			son=++top;
			son->val=x;
		}
	}
	else if(x>val)
	{
		if(daughter!=mmp)
		{
			daughter->insert(x);
		}
		else
		{
			daughter=++top;
			daughter->val=x;
		}
		return;
	}
	else
	{
		++cnt;
	}
	size=son->size+daughter->size+cnt;
	return;
}
inline node::node()
{
	val=cnt=size=0;dat=rand();
	son=daughter=mmp;
	return;
}
inline node::node(const int &ival,const int &icnt,const int &isize)
{
	val=ival;cnt=icnt;size=isize;dat=rand();
	son=daughter=mmp;
	return;
}
