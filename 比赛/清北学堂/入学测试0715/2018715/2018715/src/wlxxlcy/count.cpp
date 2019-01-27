#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int e[5][5];
char z;
bool b[130];
int pop,qu;
int main(){
    freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++){
		memset(b,0,sizeof(b));
		for(int j=1;j<=3;j++){
	  	cin>>z;
	  	e[i][j]=z-'0';
	  	b[e[i][j]]=1;
	  	if(j==3){
	  		int t=0;
	  		for(int i=1;i<=130;i++)
	  		  if(b[i]) t++;
	  		if(t==1) pop++;
	  		if(t==2) qu++;
		  }
	  }
	}
	for(int j=1;j<=3;j++){
	  memset(b,0,sizeof(b));
		for(int i=1;i<=3;i++){
	  	b[e[i][j]]=1;
	  	if(i==3){
	  		int t=0;
	  		for(int i=1;i<=130;i++)
	  		  if(b[i]) t++;
	  		if(t==1) pop++;
	  		if(t==2) qu++;
		  }
	  }
	}
	memset(b,0,sizeof(b));
	b[e[1][1]]++;b[e[2][2]]++;b[e[3][3]]++;
	int t=0;
	for(int i=1;i<=130;i++)
	if(b[i]) t++;
	if(t==1) pop++;
	if(t==2) qu++;
	memset(b,0,sizeof(b));
	b[e[1][3]]++;
	b[e[2][2]]++;
	b[e[3][1]]++;
	t=0;
	for(int i=1;i<=130;i++)
	if(b[i]) t++;
	if(t==1) pop++;
	if(t==2) qu++;
	cout<<pop<<endl;
	cout<<qu<<endl;
	return 0;
}
