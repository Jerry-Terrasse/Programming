//http://live3.aijianzi.com/record/aijianzi/2018-03-10/5555_1/1520675139_8.ts
#include<bits/stdc++.h>
using namespace std;
string s="http://live3.aijianzi.com/record/aijianzi/2018-03-10/5555_1/";
int dx[2]={37,38};
int main()
{
  int i=0,j=0;
  long long a=0;
  for(a=1520675139,i=8;i<=186;)
  {
  	cout<<s<<a<<"_"<<i<<".ts"<<endl;
  	a+=dx[i%2];
  	i++;
  }
  return 250;
}
