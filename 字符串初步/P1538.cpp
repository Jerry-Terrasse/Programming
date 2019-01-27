#include<iostream>
#include<cstring>
using namespace std;
struct number
{
  bool line1,line2[2],line3,line4[2],line5;
}data[10]={{1,1,1,0,1,1,1},{0,0,1,0,0,1,0},{1,0,1,1,1,0,1},{1,0,1,1,0,1,1},{0,1,1,1,0,1,0},{1,1,0,1,0,1,1},{1,1,0,1,1,1,1},{1,0,1,0,0,1,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
int k=0,x=0,y=0;
string s="";
int main()
{
  int i=0,j=0,n=0;
  char w='\0',c='\0';
  cin>>k>>s;
  for(n=0;n<s.length();n++)
  {
  	if(data[s[n]-'0'].line1)
  	{
  	  w='-';
	}
	else
	{
	  w=' ';
	}
	cout<<' ';
	for(i=0;i<k;i++)
	{
	  cout<<w;
	}
	cout<<' '<<' ';
  }
  cout<<endl;
  for(i=0;i<k;i++)
  {
  	for(n=0;n<s.length();n++)
    {
  	  if(data[s[n]-'0'].line2[0])
  	  {
  	    w='|';
	  }
	  else
	  {
	    w=' ';
	  }
	  if(data[s[n]-'0'].line2[1])
  	  {
  	    c='|';
	  }
	  else
	  {
	    c=' ';
	  }
	  cout<<w;
	  for(j=0;j<k;j++)
	  {
	  	cout<<' ';
	  }
	  cout<<c<<' ';
    }
    cout<<endl;
  }
  for(n=0;n<s.length();n++)
  {
  	if(data[s[n]-'0'].line3)
  	{
  	  w='-';
	}
	else
	{
	  w=' ';
	}
	cout<<' ';
	for(i=0;i<k;i++)
	{
	  cout<<w;
	}
	cout<<' '<<' ';
  }
  cout<<endl;
  for(i=0;i<k;i++)
  {
  	for(n=0;n<s.length();n++)
    {
  	  if(data[s[n]-'0'].line4[0])
  	  {
  	    w='|';
	  }
	  else
	  {
	    w=' ';
	  }
	  if(data[s[n]-'0'].line4[1])
  	  {
  	    c='|';
	  }
	  else
	  {
	    c=' ';
	  }
	  cout<<w;
	  for(j=0;j<k;j++)
	  {
	  	cout<<' ';
	  }
	  cout<<c<<' ';
    }
    cout<<endl;
  }
  for(n=0;n<s.length();n++)
  {
  	if(data[s[n]-'0'].line5)
  	{
  	  w='-';
	}
	else
	{
	  w=' ';
	}
	cout<<' ';
	for(i=0;i<k;i++)
	{
	  cout<<w;
	}
	cout<<' '<<' ';
  }
  cout<<endl;
  return 0;
}
