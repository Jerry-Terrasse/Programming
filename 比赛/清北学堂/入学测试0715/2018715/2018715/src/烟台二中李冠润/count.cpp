#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<windows.h>
using namespace std;

char in[4][4];
int team,person;

int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<4;i++)
		for(int j=1;j<4;j++)
			scanf("%c",&in[i][j]);

	if( in[0][1]==in[0][2]&&
	    in[0][0]==in[0][1]&&
	    in[0][0]==in[0][2]
	    ||
	    in[1][1]==in[1][2]&&
	    in[1][0]==in[1][1]&&
	    in[1][0]==in[1][2]
	    ||
	    in[2][1]==in[2][2]&&
	    in[2][0]==in[2][1]&&
	    in[2][0]==in[2][2]
	    ||
	    in[1][0]==in[0][0]&&
	    in[2][0]==in[0][0]&&
	    in[1][0]==in[2][0]
		||
		in[1][1]==in[0][1]&&
	    in[2][1]==in[0][1]&&
	    in[1][1]==in[2][1]
		||
		in[1][2]==in[0][2]&&
	    in[2][2]==in[0][2]&&
	    in[1][2]==in[2][2])
	    person++;
	    
	if( in[0][1]==in[0][2]||
	    in[0][0]==in[0][1]||
	    in[0][0]==in[0][2]
	    ||
	    in[1][1]==in[1][2]||
	    in[1][0]==in[1][1]||
	    in[1][0]==in[1][2]
	    ||
	    in[2][1]==in[2][2]||
	    in[2][0]==in[2][1]||
	    in[2][0]==in[2][2]
	    ||
	    in[1][0]==in[0][0]||
	    in[2][0]==in[0][0]||
	    in[1][0]==in[2][0]
		||
		in[1][1]==in[0][1]||
	    in[2][1]==in[0][1]||
	    in[1][1]==in[2][1]
		||
		in[1][2]==in[0][2]||
	    in[2][2]==in[0][2]||
	    in[1][2]==in[2][2])
	    team++;
	cout<<person<<endl<<team<<endl;
	return 0;
}

