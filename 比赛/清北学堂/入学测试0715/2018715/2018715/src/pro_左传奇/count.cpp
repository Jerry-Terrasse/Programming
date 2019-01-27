#include<iostream>
#include<cstdio>
#define rep(x) for(int x=0;x<=2;x++)
#define repc(x) for(int x='A';x<='Z';x++)
using namespace std;
char list[10][10];
char people;
int cnt;
bool peoplewin[256];
bool teamwin[256][256];
void set(char a,char b){
	teamwin[a][b]=1;
};
void test(char a,char b,char c){
	if( a==b && a==c) peoplewin[a]=1;
	else if(a == b) set(b,c);
	else if(b == c) set(c,a);
	else if(c == a) set(a,b);
	return;
	
}
int count(){
	rep(i) test(list[i][0],list[i][1],list[i][2]);
	rep(i) test(list[0][i],list[1][i],list[2][i]);
	test(list[0][0],list[1][1],list[2][2]);
	test(list[0][2],list[1][1],list[2][0]);
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	rep(i) rep(j) cin>>list[i][j];
	count();
	repc(i) cnt+=peoplewin[i];
	cout<<cnt<<endl;
	cnt=0;
	repc(i) repc(j) cnt+=teamwin[i][j];
	cout<<cnt;
}
