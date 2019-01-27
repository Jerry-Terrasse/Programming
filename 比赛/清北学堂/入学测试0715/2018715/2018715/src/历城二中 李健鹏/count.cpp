#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
string a,b,c;
int biao[10][10],ans1,ans2,now[1000],hi[10][10],n,num,s1,s2;
bool bj;
void work(){
	for(int i=1;i<=3;i++){
		if((biao[i][1]==biao[i][2])&&(biao[i][2]==biao[i][3])){
			for(int j=1;j<=num;j++)
				if(biao[i][1]==now[j]) bj=true;
			if(bj==false) ans1++,now[++num]=biao[i][1];
			bj=false;
		}
		else
		if((biao[1][i]==biao[2][i])&&(biao[2][i]==biao[3][i])){
			for(int j=1;j<=num;j++)
				if(biao[1][i]==now[j]) bj=true;
			if(bj==false) ans1++,now[++num]=biao[1][i];
			bj=false;
		}
		else 
		if((biao[i][1]==biao[i][2])||(biao[i][2]==biao[i][3])||(biao[i][1]==biao[i][3])){
			if(biao[i][1]==biao[i][2]){
				s1=biao[i][1];
				s2=biao[i][3];
			}
			else {
				s1=biao[i][1];
				s2=biao[i][2];
			}
			if((!hi[s1][s2])&&(!hi[s2][s1])){
				ans2++;
				hi[s1][s2]=1;
				hi[s1][s2]=1;
			}
		}
		else
		if((biao[1][i]==biao[2][i])||(biao[2][i]==biao[3][i])||(biao[1][i]==biao[3][i])){
			if(biao[1][i]==biao[2][i]){
				s1=biao[1][i];
				s2=biao[3][i];
			}
			else {
				s1=biao[1][i];
				s2=biao[2][i];
			}
			if((!hi[s1][s2])&&(!hi[s2][s1])){
				ans2++;
				hi[s1][s2]=1;
				hi[s1][s2]=1;
			}
		}
	}
		if((biao[1][1]==biao[2][2])&&(biao[2][2]==biao[3][3])){
		for(int j=1;j<=num;j++){
			if(biao[1][1]==now[j])bj==true;
			if(bj==false) ans1++;
			bj=false;
		}
	}
	else
	if((biao[1][3]==biao[2][2])&&(biao[2][2]==biao[3][1])){
		for(int j=1;j<=num;j++){
			if(biao[1][1]==now[j])bj==true;
			if(bj==false) ans1++;
			bj=false;
		}
	}
	else
	if((biao[1][1]==biao[2][2])||(biao[2][2]==biao[3][3])||(biao[1][1]=biao[3][3])){
			if(biao[1][1]==biao[2][2]){
				s1=biao[1][1];
				s2=biao[3][3];
			}
			else {
				s1=biao[1][1];
				s2=biao[2][2];
			}
			if((!hi[s1][s2])&&(!hi[s2][s1])){
				ans2++;
				hi[s1][s2]=1;
				hi[s1][s2]=1;
			}
	}
	else
	if((biao[1][3]==biao[2][2])||(biao[2][2]==biao[3][1])||(biao[1][3]==biao[3][1])){
			if(biao[1][3]==biao[2][2]){
				s1=biao[1][3];
				s2=biao[3][1];
			}
			else {
				s1=biao[1][3];
				s2=biao[2][2];
			}
			if((!hi[s1][s2])&&(!hi[s2][s1])){
				ans2++;
				hi[s1][s2]=1;
				hi[s1][s2]=1;
			}
	}
	return;
	}
	
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>a;
	cin>>b;
	cin>>c;
	for(int j=1;j<=3;j++){
		biao[1][j]=a[j-1];
		biao[2][j]=b[j-1];
		biao[3][j]=c[j-1];
		}
	for(int i=1;i<=3;i++)
	for(int j=1;j<=3;j++)
	biao[i][j]=biao[i][j]-'A'+1;
	work();
	cout<<ans1<<endl;
	cout<<ans2<<endl;
	return 0;
}
