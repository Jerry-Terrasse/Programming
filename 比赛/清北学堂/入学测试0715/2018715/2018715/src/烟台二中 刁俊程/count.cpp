#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char s[10][10];
int vis1[100],vis2[50],vis3[200],vis4[200],per[200],w[200][200],winner[200];
int m,ans1,ans2;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
	 for(int j=1;j<=3;j++){
	 	cin>>s[i][j];
	 }
	for(int i=1;i<=3;i++){
		memset(vis1,0,sizeof(vis1));
	    memset(winner,0,sizeof(winner)); 
		int cnt=0;
		for(int j=1;j<=3;j++){
			m=s[i][j]-'0';
			if(!vis1[m]){
				vis1[m]=1;
				cnt++;
				winner[cnt]=m;
			}			
		}
		if(cnt==1&&!per[winner[1]]) {ans1++;per[winner[1]]=1;	}
		if(cnt==2&&!w[winner[1]][winner[2]]&&!w[winner[2]][winner[1]]){ans2++;w[winner[1]][winner[2]]=1;w[winner[2]][winner[1]]=1;	} 
	}
	for(int i=1;i<=3;i++){
		memset(vis2,0,sizeof(vis2));
		memset(winner,0,sizeof(winner)); 
		int cnt=0;
		for(int j=1;j<=3;j++){
			m=s[j][i]-'0';
			if(!vis2[m]){
				vis2[m]=1;
				cnt++;
				winner[cnt]=m;
			}			
		}
		if(cnt==1&&!per[winner[1]]) {ans1++;per[winner[1]]=1;}
		if(cnt==2&&!w[winner[1]][winner[2]]&&!w[winner[2]][winner[1]]){ans2++;w[winner[1]][winner[2]]=1;w[winner[2]][winner[1]]=1;	}
	}
	int a,b,c,d,e;
	a=s[1][1]-'0',c=s[2][2]-'0',b=s[3][3]-'0',d=s[1][3]-'0',e=s[3][1]-'0';
	//cout<<a<<" "<<b<<" "<<c<<" "<<w[b][c]<<" "<<w[b][a]<<endl; 
	if(a==b){
		if(b==c&&!per[a]){ans1++;per[a]=1;		} 
		if(b!=c){
			if(!w[c][b]&&!w[b][c]) {
			  ans2++;
			  w[c][b]=1;
			  w[b][c]=1;
			}
			
    	}
    }
	if(a!=b){
		if(b==c){
			if(!w[a][b]&&!w[b][a]){
				ans2++;
				w[b][a]=1;
				w[a][b]=1;
			}
		}
		if(a==c){
			if(!w[b][c]&&!w[c][b]){
				ans2++;
				w[b][c]=1;
				w[c][b]=1;
			}
		} 
	}
	if(c==d){
		if(d==e&&!per[c]){ans1++;per[c]=1;		} 
		if(d!=e){
			if(!w[c][e]&&!w[e][c]) {
			  ans2++;
			  w[c][e]=1;
			  w[e][c]=1;
			}
			
    	}
    }
	if(c!=d){
		if(d==e){
			if(!w[c][e]&&!w[e][c]){
				ans2++;
				w[d][e]=1;
				w[e][d]=1;
			}
		}
		if(e==c){
			if(!w[c][d]&&!w[d][c]){
				ans2++;
				w[c][d]=1;
				w[d][c]=1;
			}
		} 
	}
	cout<<ans1<<endl;
	cout<<ans2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
