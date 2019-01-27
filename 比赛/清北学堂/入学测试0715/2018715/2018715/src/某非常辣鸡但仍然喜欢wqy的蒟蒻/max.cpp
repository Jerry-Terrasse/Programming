#include <iostream>
#include <cstdio>
#include <algorithm>
#define LL long long
#define N 100005
#define F(i,a,b) for (int i=a;i<=b;++i)

using namespace std;

int n,l;
LL va,vb;
LL now,ans;
struct mountain{
	LL h;
	LL c;
}hign[N];


inline LL read(){
	LL s=0,w=1;
	char ch=getchar();
	while (ch>'9'||ch<'0') {if (ch=='-') w=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
inline bool cmp(mountain x,mountain y){
	return x.c>y.c;	
}

int main(void){
	freopen ("max.in","r",stdin);
	freopen ("max.out","w",stdout);
	scanf("%d%d",&l,&n);
	va=read();
	vb=read();
	F(i,1,n){
		hign[i].h=read();
		hign[i].c=read();
	}
	LL shq=hign[1].h;
	LL lgy=hign[1].h;
	sort(hign+1,hign+n+1,cmp);
	now=hign[1].h*(va-vb);
	ans+=now*hign[1].c;
	F(i,2,n)
		if(hign[i].h>shq){
		ans=ans+hign[i].c*(hign[i].h-shq)*(va-vb);
		shq=hign[i].h;
		lgy=hign[i].h;
	 }
	printf ("%d\n",ans);
	return 0;
}
