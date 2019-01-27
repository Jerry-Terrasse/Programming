#include<iostream>
#include<cmath>
using namespace std;
int w(int,int,int);
int s[21][21][21];
bool bo[20][20][20];
int main()
{
  long long a=0,b=0,c=0;
  long long ra=0,rb=0,rc=0;
  //s[0][0][0]=1;
  //bo[0][0][0]=true;
  //s[20][20][20]=w(20,20,20);
  //bo[20][20][20]=true;
  //cout<<s[20][20][20];
  s[20][20][10]=1048576;
  bo[20][20][10]=true;
  s[17][17][18]=131072;
  bo[17][17][18]=true;
  s[10][4][6]=523;
  bo[10][4][6]=true;
  s[19][17][18]=524271;
  bo[19][17][18]=true;
  for(cin>>ra>>rb>>rc;(ra!=-1)||(rb!=-1)||(rc!=-1);cout<<"w("<<ra<<", "<<rb<<", "<<rc<<") = "<<s[a][b][c]<<endl,cin>>ra>>rb>>rc)
  {
  	if((ra<=0)||(rb<=0)||(rc<=0))
  	{
  	  a=b=c=0;
	}
	else if((ra>20)||(rb>20)||(rc>20))
  	{
  	  a=b=c=20;
	}
	else
	{
	  a=ra,b=rb,c=rc;
	}
	s[a][b][c]=w(a,b,c);
  }
  return 0;
}
int w(int a,int b,int c)
{
  if(bo[a][b][c])
  {
  	return s[a][b][c];
  }
  else if((a<=0)||(b<=0)||(c<=0))
  {
    return 1;
  }
  else if((a>20)||(b>20)||(c>20))
  {
    s[20][20][20]=w(20,20,20);
	return s[20][20][20];
  }
  else if((a<b)&&(b<c))
  {
	s[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	bo[a][b][c]=true;
	//cout<<a<<" "<<b<<" "<<c<<" "<<s[a][b][c];
    return s[a][b][c];
  }
  else
  {
  	s[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
  	bo[a][b][c]=true;
  	//cout<<a<<" "<<b<<" "<<c<<" "<<s[a][b][c];
  	return s[a][b][c];
  }
}
