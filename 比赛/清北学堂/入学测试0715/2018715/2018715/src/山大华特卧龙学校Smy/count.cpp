#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int s[5][5];
char c;
bool b[130];
int aa,bb;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++){
		memset(b,0,sizeof(b));
		for(int j=1;j<=3;j++){
	  	cin>>c;
	  	s[i][j]=c-'0';
	  	b[s[i][j]]=1;
	  	if(j==3){
	  		int t=0;
	  		for(int i=1;i<=130;i++)
	  		  if(b[i]) t++;
	  		if(t==1) aa++;
	  		if(t==2) bb++;
		  }
	  }
	}
	for(int j=1;j<=3;j++){
	  memset(b,0,sizeof(b));
		for(int i=1;i<=3;i++){
	  	b[s[i][j]]=1;
	  	if(i==3){
	  		int t=0;
	  		for(int i=1;i<=130;i++)
	  		  if(b[i]) t++;
	  		if(t==1) aa++;
	  		if(t==2) bb++;
		  }
	  }
	}
	memset(b,0,sizeof(b));
	b[s[1][1]]++;b[s[2][2]]++;b[s[3][3]]++;
	int t=0;
	for(int i=1;i<=130;i++)
	if(b[i]) t++;
	if(t==1) aa++;
	if(t==2) bb++;
	memset(b,0,sizeof(b));
	b[s[1][3]]++;b[s[2][2]]++;b[s[3][1]]++;
	t=0;
	for(int i=1;i<=130;i++)
	if(b[i]) t++;
	if(t==1) aa++;
	if(t==2) bb++;
	cout<<aa<<endl;
	cout<<bb<<endl;
	return 0;
}
