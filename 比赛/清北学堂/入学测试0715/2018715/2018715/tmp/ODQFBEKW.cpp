#include<iostream>
using namespace std;
char a[3][3],s[10],person[26],group[26][26];
int sum1,sum2;
void pd(char x,char y,char z){
	int book[26]={0};
	book[x-'A']++;
	book[y-'A']++;
	book[z-'A']++;
	for(int i=0;i<=25;i++)
		if(book[i]==2){
			for(int j=0;j<=25;j++)
				if(book[j]==1&&!group[i][j]){
					group[i][j]=group[j][i]=1;
					sum2++;
				}
		}
		else
			if(book[i]==3&&!person[i]){
				person[i]=1;
				sum1++;
			}
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=0;i<3;i++)
		cin>>a[i];
	int r=0,c=0;
	for(int i=1;i<=9;i++){
		s[i]=a[r][c];
		c++;
		if(c>2){
			c=0;
			r++;
		}
	}
	pd(s[1],s[2],s[3]);
	pd(s[4],s[5],s[6]);
	pd(s[7],s[8],s[9]);
	pd(s[1],s[4],s[7]);
	pd(s[2],s[5],s[8]);
	pd(s[3],s[6],s[9]);
	pd(s[1],s[5],s[9]);
	pd(s[3],s[5],s[7]);
	cout<<sum1<<endl<<sum2;
	return 0;
}
