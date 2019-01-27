#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char ch[4][4];
bool ok[101];//¸öÈË 
bool okt[101][101];//¶ÓÎé 
int sumn[101];
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
		scanf("%s",ch[i]+1);
	for(int i=1;i<=3;i++){
		memset(sumn,0,sizeof(sumn));
		for(int j=1;j<=3;j++){
			int chi=ch[i][j];
			sumn[chi]++;
			if(sumn[chi]==3) ok[chi]=true;
		}
		for(int j=1;j<=3;j++){
			int chi=ch[i][j];
			bool yi=false;
			if(sumn[chi]==2){
				for(int k=1;k<=3;k++){
					int chii=ch[i][k];
					if(sumn[chii]==1){
						int maxn=max(chi,chii);
						int minn=min(chi,chii);
						okt[maxn][minn]=true;
						yi=true; 
						break;
					}
				}
			}
			if(yi==true) break;
		}
		memset(sumn,0,sizeof(sumn));
		for(int j=1;j<=3;j++){
			int chi=ch[j][i];
			sumn[chi]++;
			if(sumn[chi]==3) ok[chi]=true;
		}
		for(int j=1;j<=3;j++){
			int chi=ch[j][i];
			bool yi=false;
			if(sumn[chi]==2){
				for(int k=1;k<=3;k++){
					int chii=ch[k][i];
					if(sumn[chii]==1){
						int maxn=max(chi,chii);
						int minn=min(chi,chii);
						okt[maxn][minn]=true;
						yi=true; 
						break;
					}
				}
			}
			if(yi==true) break;
		}
	}
	memset(sumn,0,sizeof(sumn));
	for(int i=1;i<=3;i++){
		int chi=ch[i][i];
		sumn[chi]++;
	}
	for(int i=1;i<=3;i++){
		int chi=ch[i][i];
		bool yi=false;
		if(sumn[chi]==3){
			ok[chi]=true;
			break;
		}
		else
		{
			if(sumn[chi]==2){
				for(int j=1;j<=3;j++){
					int chii=ch[j][j];
					if(sumn[chii]==1){
						int maxn=max(chi,chii);
						int minn=min(chi,chii);
						okt[maxn][minn]=true;
						yi=true;
					}
				}
			}
			if(yi==true) break;
		}
	}
	memset(sumn,0,sizeof(sumn));
	for(int i=1;i<=3;i++){
		int chi=ch[i][4-i];
		bool yi=false;
		if(sumn[chi]==3){
			ok[chi]=true;
			break;
		}
		else
		{
			if(sumn[chi]==2){
				for(int j=1;j<=3;j++){
					int chii=ch[j][4-j];
					if(sumn[chii]==1){
						int maxn=max(chi,chii);
						int minn=min(chi,chii);
						okt[maxn][minn]=true;
						yi=true;
					}
				}
			}
			if(yi==true) break;
		}
	}
	int ans1=0;
	for(int i='A';i<='Z';i++)
		if(ok[i]==true) ans1++;
	printf("%d\n",ans1);
	int ans2=0;
	for(int i='A';i<='Z';i++)
		for(int j='A';j<i;j++)
			if(okt[i][j]==true) ans2++;
	printf("%d",ans2);
	fclose(stdin); fclose(stdout);
	return 0;
}
