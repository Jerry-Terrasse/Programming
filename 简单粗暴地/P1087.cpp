#include<iostream>
#include<cstring>
using namespace std;
struct node
{
  int len;
  char val;
  node *son,*daughter;
  char build(string);
  void output();
}*head;
string s="";
int main()
{
  int i=0;
  cin>>i>>s;
  head=new node;
  head->build(s);
  head->output();
  cout<<endl;
  return 0;
}
void node::output()
{
  if(len==1)
  {
  	cout<<val;
  	return;
  }
  son->output();
  daughter->output();
  cout<<val;
  return;
}
char node::build(string is)
{
  char l='\0',r='\0';
  len=is.length();
  if(len==1)
  {
  	val=is[0]=='1'?'I':'B';
	return val;
  }
  son=new node;
  daughter=new node;
  l=son->build(is.substr(0,len>>1));
  r=daughter->build(is.substr(len>>1,len>>1));
  val=l==r?l:'F';
  return val;
}
