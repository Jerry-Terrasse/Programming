#include<iostream>
using namespace std;
class noname
{
  public:
  void init();
  void make();
  void output();
  void left();
  void right();
  void up();
  void down();
  void set();
  void ori();
  void bool over();
  private:
  int num[5][5];
  int 
};
noname mian;
int main()
{
  int i=0;
  char o='\0';
  mian.init()
  mian.make();
  for(;;)
  {
  	mian.output();
  	for(mian.set();;)
  	{
  	  cin>>o;
  	  if(o=='l')
  	  {
  	    mian.left();
	  }
	  else if(o=='r')
	  {
	  	mian.right();
	  }else if(o=='u')
	  {
	  	mian.up();
	  }else if(o=='d')
	  {
	  	mian.down();
	  }
	  if(mian.ori())
	  {
	  	continue;
	  }
	  break;
	}
	mian.output();
	if(mian.over())
	{
	  break;
	}
  }
  return 0;
}
