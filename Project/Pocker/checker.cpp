#include<iostream>
#include "memory.h"
#include<cstring>
#include<algorithm>
#define MAXN 16
using namespace std;
bool lim=false;
int card[MAXN],pre[MAXN],pcnt=0,ccnt=0,cf=0,pf=0,ck=0,pk=0;
string s="",pr="";
inline void exchange();
inline bool ok(string);
inline void deal();
int main()
{
  int i=0;
  cin>>s>>pr;
  if(pr!="NONE")
  {
  	lim=true;
  }
  exchange();
  if(ok())
  {
	cout<<"YES"<<endl;
  }
  else
  {
  	cout<<"NO"<<endl;
  }
  return 0;
}
inline void deal()
{
  int i=0;
  switch(pcnt)
  {
  	case 1:
  	  pk=1;
  	  pf=pre[0];
	  break;
  	case 2:
  	  if(pre[0]==pre[1])
  	  {
  	    pk=2;
  	    pf=pre[0];
	  }
  	  else
  	  {
  	    pk=8;
  	    pf=71;
	  }
  	  break;
  	case 4:
	  for(i=1;i<=4;i++)
  	  {
  	  	if(pre[i]!=pre[i-1])
  	  	{
  	  	  break;
		}
	  }
	  if(i==1)
	  {
	  	pk=3;
		pf=pre[1];
	  }
	  else if(i==3)
	  {
	  	pk=3;
		pf=pre[0];
	  }
	  else
	  {
	  	pk=7;
	  	pf=pre[0];
	  }
  	  break;
  	default:
  	  int rec[110];
  	  memset(rec,0,sizeof(rec));
  	  
  	  break;
  }
  return;
}
inline void exchange()
{
  int i=0;
  if(lim)
  {
  	for(;i<pr.length();i++)
    {
  	  if(i&1)
  	  {
  	    continue;
	  }
	  pre[pcnt++]=pr[i];
    }
    sort(pre,pre+pcnt);
  }
  for(i=0;i<s.length();i++)
  {
  	if(i&1)
  	{
  	  continue;
	}
	card[ccnt++]=s[i];
  }
  sort(card,card+ccnt);
  return;
}
inline bool ok(string s)
{
  int i=0,j=0;
  if(lim)
  {
  	deal();
  }
  switch(ccnt)
  {
  	case 1:
  	  if(!lim)
  	  {
  	    return true;
	  }
	  if(pcnt!=1)
	  {
	  	return false;
	  }
	  pf=pre[0];
	  cf=card[0];
	  if(cf>pf)
	  {
	  	return true;
	  }
  	  break;
  	case 2:
	  if(card[0]==70 && card[1]==71)
	  {
	    return true;
	  }
  	  if(!lim)
  	  {
  	    if(card[0]==card[1])
  	    {
  	      return true;
		}
		else
		{
		  return false;
		}
	  }
	  if(pre[0]==pre[1])
	  {
	  	pk=2;
	  	pf=pre[0];
	  }
	  else
	  {
	  	return false;
	  }
	  if(card[0]=card[1])
	  {
	  	cf=card[0];
	  }
	  else
	  {
	  	return false;
	  }
	  if(cf>pf)
	  {
	  	return true;
	  }
  	  break;
  	case 3:
  	  if(!lim && cin>>i)
  	  {
  	  	return true;
	  }
  	  break;
  	case 4:
  	  for(i=1;i<=4;i++)
  	  {
  	    if(card[i]!=card[i-1])
  	    {
  	      break;
		}
	  }
	  if(i==4)
	  {
	  	ck=7;
	  	cf=card[0];
	  }
	  else
	  {
	  	if(i==3)
	  	{
	  	  ck=3;
		  cf=card[0];
		}
		else if(i==1)
		{
		  if(card[1]==card[2] && card[2]==card[3])
		  {
		  	ck=3;
		  	cf=card[1];
		  }
		  else
		  {
		  	return false;
		  }
		}
		else
		{
		  return false;
		}
	  }
  	  break;
  	default:
  	  break;
  }
  return false;
}
