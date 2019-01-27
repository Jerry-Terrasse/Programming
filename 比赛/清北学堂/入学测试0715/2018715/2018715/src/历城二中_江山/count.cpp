#include<cstdio>
#include<iostream>
using namespace std;
string st[4];
bool ch1[27],ch2[27][27];
int ans1,ans2;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>st[1];
	cin>>st[2];
	cin>>st[3];
	st[1]=' '+st[1];
	st[2]=' '+st[2];
	st[3]=' '+st[3];
	for(int i=1;i<=3;++i){
		if((st[i][1]==st[i][2])&&(st[i][2]==st[i][3])){
			int lala=(int)st[i][1]-'A'+1;
			if(!ch1[lala]){
				ans1++;
				ch1[lala]=1;
			}
		}
		else
			if((st[i][1]==st[i][2])||(st[i][1]==st[i][3])||(st[i][2]==st[i][3])){
				int lala1=(int)st[i][1]-'A'+1,lala2=(int)st[i][2]-'A'+1,lala3=(int)st[i][3]-'A'+1;
				int la1=0,la2=0;
				if(lala1==lala2){
					la1=lala1;
					la2=lala3;
				}
				else{
					la1=lala1;
					la2=lala2;
				}
				if((!ch2[la1][la2])&&(!ch2[la2][la1])){
					ans2++;
					ch2[la1][la2]=1;
					ch2[la2][la1]=1;
				}
			}
	}
	for(int i=1;i<=3;++i){
		if((st[1][i]==st[2][i])&&(st[2][i]==st[3][i])){
			int lala=(int)st[1][i]-'A'+1;
			if(!ch1[lala]){
				ans1++;
				ch1[lala]=1;
			}
		}
		else
			if((st[1][i]==st[2][i])||(st[1][i]==st[3][i])||(st[2][i]==st[3][i])){
				int lala1=(int)st[1][i]-'A'+1,lala2=(int)st[2][i]-'A'+1,lala3=(int)st[3][i]-'A'+1;
				int la1=0,la2=0;
				if(lala1==lala2){
					la1=lala1;
					la2=lala3;
				}
				else{
					la1=lala1;
					la2=lala2;
				}
				if((!ch2[la1][la2])&&(!ch2[la2][la1])){
					ans2++;
					ch2[la1][la2]=1;
					ch2[la2][la1]=1;
				}
			}
	}
	if((st[1][1]==st[2][2])&&(st[2][2]==st[3][3])){
		int lala=(int)st[1][1]-'A'+1;
		if(!ch1[lala]){
			ans1++;
			ch1[lala]=1;
		}
	}
	else
		if((st[1][1]==st[2][2])||(st[1][1]==st[3][3])||(st[2][2]==st[3][3])){
			int lala1=(int)st[1][1]-'A'+1,lala2=(int)st[2][2]-'A'+1,lala3=(int)st[3][3]-'A'+1;
			int la1=0,la2=0;
			if(lala1==lala2){
				la1=lala1;
				la2=lala3;
			}
			else{
				la1=lala1;
				la2=lala2;
			}
			if((!ch2[la1][la2])&&(!ch2[la2][la1])){
					ans2++;
					ch2[la1][la2]=1;
					ch2[la2][la1]=1;
			}
		}
	if((st[1][3]==st[2][2])&&(st[2][2]==st[3][1])){
		int lala=(int)st[1][3]-'A'+1;
		if(!ch1[lala]){
			ans1++;
			ch1[lala]=1;
		}
	}
	else
		if((st[1][3]==st[2][2])||(st[1][3]==st[3][1])||(st[2][2]==st[3][1])){
			int lala1=(int)st[1][3]-'A'+1,lala2=(int)st[2][2]-'A'+1,lala3=(int)st[3][1]-'A'+1;
			int la1=0,la2=0;
			if(lala1==lala2){
				la1=lala1;
				la2=lala3;
			}
			else{
				la1=lala1;
				la2=lala2;
			}
			if((!ch2[la1][la2])&&(!ch2[la2][la1])){
					ans2++;
					ch2[la1][la2]=1;
					ch2[la2][la1]=1;
			}
		}
	printf("%d\n%d",ans1,ans2);
	return 0;
}
