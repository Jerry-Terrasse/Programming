#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#define ld long double
#define db double
#define MAXT 1e6
#define rr(x) (rand()%(x))
#define rrr(x) (rand()*rand()%x)
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
ld p=0,w=0,ans=0;
int t=0;
int main()
{
  register int i=0,j=0;
  //cin>>p;
  w=p=(ld)1/3;
  for(t=0;t<100;++t)
  {
  	
  srand(time(NULL));
  	for(i=0,w=1;i<MAXT;++i)
  {
  	if((db)rand()/RAND_MAX<w)
  	{
  	  w=p;
  	  ++j;
	}
	else
	{
	  w+=p;
	}
  }
  /*if(ans==0)
  {
  	ans=(ld)j/MAXT;
  }
  else
  {
  	ans=((ld)j/MAXT+ans)/2;
  }*/
  }
  cout<<fixed<<setprecision(3)<<(ld)j/(MAXT*100)<<endl;
  return 0;
}
