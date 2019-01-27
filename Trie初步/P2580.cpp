#include<iostream>
#include<cstring>
using namespace std;
struct letter
{
  int end;
  letter *son[26];
}*head;
int n=0;
int main()
{
  int i=0,j=0,k=0,bo=0;
  string s="";
  letter *p=NULL;
  ios::sync_with_stdio(0);
  head=new letter;
  head->end=0;
  for(;k<26;k++)
  {
  	head->son[k]=NULL;
  }
  for(cin>>n;i<n;i++)
  {
    cin>>s;
    p=head;
	for(j=0;j<=s.length()-1;j++)
    {
      if(p->son[s[j]-'a']==NULL)
      {
      	p->son[s[j]-'a']=new letter;
	    p=p->son[s[j]-'a'];
	    p->end=0;
	    for(k=0;k<26;k++)
        {
  	      p->son[k]=NULL;
        }
	  }
	  else
	  {
	  	p=p->son[s[j]-'a'];
	  }
	}
	p->end=1;
  }
  for(i=0,cin>>n;i<n;i++)
  {
  	cin>>s;
  	bo=0;
	p=head;
	for(j=0;j<s.length();j++)
  	{
  	  if(p->son[s[j]-'a']==NULL)
  	  {
  	    bo=1;
  	    break;
	  }
	  else
	  {
	  	//cout<<"get in to"<<s[j]<<endl;
		p=p->son[s[j]-'a'];
	  }
	}
	if(bo)
	{
	  cout<<"WRONG\n";
	}
	else
	{
	  if(p->end==0)
	  {
	  	cout<<"Wrong\n";
	  }
	  else if(p->end==1)
	  {
	  	cout<<"OK\n";
	  	p->end++;
	  }
	  else if(p->end==2)
	  {
	  	cout<<"REPEAT\n";
	  }
	}
  }
  return 0;
}
