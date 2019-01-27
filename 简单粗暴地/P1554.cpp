#include<iostream>
#include<sstream>
using namespace std;
int n=0,m=0,cnt[10];
stringstream sio;
int main()
{
  int i=0;
  char c='\0';
  cin>>m>>n;
  for(i=m;i<=n;i++)
  {
    sio<<i;
  }
  sio<<'@';
  for(;;)
  {
  	sio>>c;
  	if(c=='@')
  	{
  	  break;
	}
	cnt[c-'0']++;
  }
  for(i=0;i<=9;i++)
  {
  	cout<<cnt[i]<<' ';
  }
  return 0;
}
