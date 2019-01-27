#include<iostream>
#include<queue>
#include<set>
using namespace std;
struct node
{
  int ha,mp[8];
  string step;
};
queue<node>q;
set<int>st;
node h,p;
int has=0;
void haash();
void test();
int main()
{
  int i=0,j=0;
  for(i=0;i<4;i++)
  {
  	cin>>p.mp[i];
  }
  for(i=7;i>=4;i--)
  {
  	cin>>p.mp[i];
  }
  p.step="";
  haash();
  has=p.ha;
  //cout<<has<<endl;
  //system("pause");
  for(i=0;i<4;i++)
  {
  	p.mp[i]=i+1;
  	p.mp[i+4]=8-i;
  }
  haash();
  if(has==p.ha)
  {
  	cout<<p.step.length()<<endl;
    cout<<p.step<<endl;
    return 0;
  }
  st.insert(p.ha);
  q.push(p);
  for(;!q.empty();)
  {
  	h=q.front();
  	q.pop();
  	p.step=h.step+'A';
	for(i=0;i<4;i++)
  	{
  	  p.mp[i+4]=h.mp[i];
	  p.mp[i]=h.mp[i+4];
	}
	haash();
	if(p.ha==has)
	{
	  break;
	}
	if(st.count(p.ha)==0)
	{
	  st.insert(p.ha);
	  q.push(p);
	  //test();
	}
	p.step=h.step+'B';
	p.mp[0]=h.mp[3];
	p.mp[1]=h.mp[0];
	p.mp[2]=h.mp[1];
	p.mp[3]=h.mp[2];
	p.mp[4]=h.mp[7];
	p.mp[5]=h.mp[4];
	p.mp[6]=h.mp[5];
	p.mp[7]=h.mp[6];
	haash();
	if(p.ha==has)
	{
	  break;
	}
	if(st.count(p.ha)==0)
	{
	  st.insert(p.ha);
	  q.push(p);
	  //test();
	}
	p.step=h.step+'C';
	p.mp[0]=h.mp[0];
	p.mp[1]=h.mp[5];
	p.mp[2]=h.mp[1];
	p.mp[3]=h.mp[3];
	p.mp[4]=h.mp[4];
	p.mp[5]=h.mp[6];
	p.mp[6]=h.mp[2];
	p.mp[7]=h.mp[7];
	haash();
	if(p.ha==has)
	{
	  break;
	}
	if(st.count(p.ha)==0)
	{
	  st.insert(p.ha);
	  q.push(p);
	  //test();
	}
	//system("pause");
  }
  cout<<p.step.length()<<endl;
  cout<<p.step<<endl;
  return 0;
}
void test()
{
  //if(p.step=="BCABCCB")
  {
  	for(int kk=0;kk<8;kk++)
  	{
  	  cout<<p.mp[kk]<<' ';
	}
	cout<<endl;
  }
}
void haash()
{
  int i=0;
  for(p.ha=0;i<8;i++)
  {
  	p.ha*=9;
  	p.ha+=p.mp[i];
  }
  return;
}
