#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
char ch[4][4];
int peo=0,tea=0;
int main()
{
	freopen("count.in","r","stdin");
	freopen("count.out","w","stdout");
	for(int i=1;i<=3;i++)
	  for(int j=1;j<=3;j++)
	  {
	  	cin>>ch[i][j];
	  }
	if(ch[1][1]==ch[2][1]&&ch[3][1]==ch[1][1])
	  peo++;
	else if(ch[1][1]==ch[2][1]&&ch[3][1]!=ch[1][1])
	  tea++;
	else if(ch[1][1]!=ch[2][1]&&(ch[3][1]==ch[1][1]||ch[3][1]==ch[2][1]))
	  tea++;
	else if(ch[1][1]==ch[1][2]&&ch[1][3]==ch[1][1])
	  peo++;
	else if(ch[1][1]==ch[1][2]&&ch[1][3]!=ch[1][1])
	  tea++;
	else if(ch[1][1]!=ch[1][2]&&(ch[1][3]==ch[1][1]||ch[1][3]==ch[1][2]))
	  tea++;
	else if(ch[1][1]==ch[2][2]&&ch[3][3]==ch[1][1])
	  peo++;
	else if(ch[1][1]==ch[2][2]&&ch[3][3]!=ch[1][1])
	  tea++;
	else if(ch[1][1]!=ch[2][2]&&(ch[3][3]==ch[1][1]||ch[3][3]==ch[2][2]))
	  tea++;
	else if(ch[3][1]==ch[2][2]&&ch[1][3]==ch[3][1])
	  peo++;
	else if(ch[3][1]==ch[2][2]&&ch[1][3]!=ch[3][1])
	  tea++;
	else if(ch[3][1]!=ch[2][2]&&(ch[1][3]==ch[3][1]||ch[1][3]==ch[2][2]))
	  tea++;
	else if(ch[2][1]==ch[2][2]&&ch[2][3]==ch[2][1])
	  peo++;
	else if(ch[2][1]==ch[2][2]&&ch[2][3]!=ch[2][1])
	  tea++;
	else if(ch[2][1]!=ch[2][2]&&(ch[2][3]==ch[2][1]||ch[2][3]==ch[2][2]))
	  tea++;
	else if(ch[3][1]==ch[3][2]&&ch[3][3]==ch[3][1])
	  peo++;
	else if(ch[3][1]==ch[3][2]&&ch[3][3]!=ch[3][1])
	  tea++;
	else if(ch[3][1]!=ch[3][2]&&(ch[3][3]==ch[3][1]||ch[3][3]==ch[3][2]))
	  tea++;
	else if(ch[1][2]==ch[2][2]&&ch[3][2]==ch[1][2])
	  peo++;
	else if(ch[1][2]==ch[2][2]&&ch[3][2]!=ch[1][2])
	  tea++;
	else if(ch[1][2]!=ch[2][2]&&(ch[3][2]==ch[1][2]||ch[3][2]==ch[2][2]))
	  tea++;
	else if(ch[1][3]==ch[2][3]&&ch[3][3]==ch[1][3])
	  peo++;
	else if(ch[1][3]==ch[2][3]&&ch[3][3]!=ch[1][3])
	  tea++;
	else if(ch[1][3]!=ch[2][3]&&(ch[3][3]==ch[1][3]||ch[3][3]==ch[2][3]))
	  tea++;
	cout<<peo<<endl;
	cout<<tea<<endl;
	return 0;
}
