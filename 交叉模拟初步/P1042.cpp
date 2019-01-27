#include<iostream>
#include<cmath>
using namespace std;
const int p[2]={10,20};
int s[2][9999][2],i[2];
string a="",b="";
int main()
{
  int k=0,j[2];
  //cin>>b;
  for(;cin>>a;b+=a);
  #define i i[k]
  #define j j[k]
	for(k=0;k<=1;k++)
  {
		j=0;
		for(i=0;(i<=b.length())&&(b[i]!='E');i++)
		{
			s[k][j][(b[i]=='L')]++;
			if(((s[k][j][0]-p[k])*(s[k][j][1]-p[k])<0)||((s[k][j][0]>=p[k])&&(s[k][j][1]>=p[k])&&(abs(s[k][j][0]-s[k][j][1])>=2)))
			{
				j++;
			}
		}
	}
	for(k=0;k<=1;k++)
	{
		for(i=0;i<=j;i++)
		{
			cout<<s[k][i][0]<<':'<<s[k][i][1]<<endl;
		}
		cout<<endl;
	}
	#undef i
	#undef j
  return 0;
}
