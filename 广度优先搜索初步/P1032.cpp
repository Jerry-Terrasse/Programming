#include<iostream>
#include<cmath>
//#include<cstring>
using namespace std;
int whash(string);
string a="",b="";
string c[6][2];
string re[999999];
int step[999999];
short ed[999999];
int main()
{
  int i=0,h=0,t=0,j=0,k=0,l=0,bo=false;
  cin>>a>>b;
  for(;(i<=5)&&(cin>>c[i][0]>>c[i][1]);i++);
  i--;
  for(re[0]=a,step[0]=0;(re[h]!=b)&&(step[h]<=9)&&(re[h]!="");h++)
  {
  	for(j=0;j<=i;j++)
  	{
  	  for(k=re[h].find(c[j][0]);-1!=k;k=re[h].find(c[j][0],k+1))
  	  {
		t++;
		re[t]=re[h];
		re[t].replace(k,c[j][0].length(),c[j][1]);
		if(ed[whash(re[t])])
		{
		  /*bo=false;
		  for(l=0;l<=t-1;l++)
		  {
		    if(re[l]==re[t])
		    {
		    	bo=true;
		    	break;
		    }
		  }
		  if(bo)
		  {*/
		    t--;
		    continue;
	      //}
		}
		step[t]=step[h]+1;
		ed[whash(re[t])]=true;
		//cout<<t<<":"<<step[h]<<":"<<re[h]<<endl<<"->"<<step[t]<<":"<<re[t]<<endl;
	  }
	  /*if(-1!=k)
  	  {
  	  	for(;)
		t++;
		re[t]=re[h];
		step[t]=step[h]+1;
		re[t].replace(k,c[j][0].length(),c[j][1]);
		cout<<t<<":"<<step[h]<<":"<<re[h]<<endl<<"->"<<step[t]<<":"<<re[t]<<endl;
	  }*/
	}
  }
  if(re[h]==b)
  {
  	cout<<step[h]<<endl;
  }
  else
  {
  	//out<<re[h];
	cout<<"NO ANSWER!"<<endl;
  }
  return 0;
}
int whash(string str)
{
  int i=0,hs=0,temp=0,po=96;
  //cout<<str<<":";
  for(i=0;i<=(int)str.length()-1;i++)
  {
  	hs*=po;
  	hs+=str[i]-'!';
  	hs%=1000000;
  }
  //cout<<hs<<endl;
  return hs;
}
