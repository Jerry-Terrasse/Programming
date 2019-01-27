#include<iostream>
#include<ctime>
#include<cstdlib>
#define MAXN 100010
using namespace std;
int n=0;
inline int rr(const int&);
int main()
{
  int i=0;
  srand(time(NULL));
  n=rr(MAXN);
  cout<<n<<endl;
  for(;n--;)
  {
  	i=rr(3);
	if(i==0)
	{
	  cout<<"sos "<<rr(MAXN)<<"bug"<<endl;
	}
	else if(i==1)
	{
	  cout<<"min"<<endl;
	}
	else if(i==2)
	{
	  cout<<"ok"<<endl;
	}
  }
  return 0;
}
inline int rr(const int &x)
{
  return rand()*rand()%x;
}
