#include<iostream>
using namespace std;
int main()
{
  int N=0,i=0,j=0,x=0,y=0;
  cin>>N>>i>>j;
  for(y=1;y<=N;y++)
  {
  	cout<<"("<<i<<","<<y<<") ";
  }
  cout<<endl;
  for(x=1;x<=N;x++)
  {
  	cout<<"("<<x<<","<<j<<") ";
  }
  cout<<endl;
  for(x=i,y=j;(x!=1)&&(y!=1);x--,y--);
  for(;(x!=4)&&(y!=4);x++,y++)
  {
  	cout<<"("<<x<<","<<y<<") ";
  }
  cout<<endl;
  for(x=i,y=j;(x!=1)&&(y!=1);x--,y--);
  for(;(x!=4)&&(y!=4);x++,y++)
  {
  	cout<<"("<<x<<","<<y<<") ";
  }
  cout<<endl;
}
