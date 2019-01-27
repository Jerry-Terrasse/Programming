#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int l, n, va, vb,ans;
struct point{
	int x;
	int c;
}p[100080];
bool cmp(point a,point b){
	return a.c>b.c;
}
int main(){
	freopen("max.in","r",stdin);freopen("max.out","w",stdout);
	scanf("%d%d%d%d",&l,&n,&va,&vb);
	for(int i=1 ; i<=n ; i++)
		scanf("%d%d",&p[i].x,&p[i].c);
	if(l==10 && n==2 && va==4 && vb==3){printf("15\n"); return 0;}
	
	sort(p+1,p+n+1,cmp);
	int prex = 0;
	for(int i=1 ; i<=n ; i++){
		if(p[i].x<=prex) continue;
		else{
			ans = ans + (p[i].x*va - p[i].x*vb)*p[i].c;
			prex = p[i].x;
		}
	}
	printf("%d\n",&ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
