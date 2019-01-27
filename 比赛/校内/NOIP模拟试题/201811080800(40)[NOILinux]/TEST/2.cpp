#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
#define ri register int
#define rc register char
#define N 100100
set<int> S[N];
int n,m,d,g;
int a[N];
int ans[N];
inline int read(){
	ri res=0;
	rc c=getchar();
	for(;c<'0' || c>'9';c=getchar());
	for(;c>='0' && c<='9';c=getchar())
		res=(res<<3)+(res<<1)+(c^'0');
	return res;
}
void write(const int& x){
	if(x>9)
		write(x/10);
	putchar(x%10^'0');
}
int main(){
	n=read(),m=read();
	for(ri i=1;i<n;i++)
		a[i]=read();
	for(ri i=1;i<=m;i++){
		g=read(),d=read();
		for(ri j=g;j;j=a[j])
			if(!S[j].count(d)){
				ans[j]++;
				S[j].insert(d);
			}
			else
				break;
		if(!S[0].count(d)){
			ans[0]++;
			S[0].insert(d);
		}
	}
	for(ri i=0;i<n;i++){
		write(ans[i]);
		puts("");
	}
	return 0;
}
/*
5 4
0
0
1
1
4 1
3 1
2 2
4 2
*/
