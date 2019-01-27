#include<map>
#include<cstdio>
#include<algorithm>

inline void qr(int &x) {
	char ch=getchar();bool f=false;
	while(ch>'9'||ch<'0') {
		if(ch=='-')	f=true;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')	x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	if(f) x=-x;
}

inline int max(const int &a,const int &b) {if(a>b)return a;else return b;}
inline int min(const int &a,const int &b) {if(a<b)return a;else return b;}
inline int abs(const int &x) {if(x>=0) return x;else return -x;}

inline void swap(char &a,char &b) {
	char temp=a;a=b;b=temp;
}

char chess[20][20];
std::map<std::pair<int,int>,bool>m;
std::map<char,int>n;
int person,group;

void check(int xi,int yi,int xj,int yj,int xk,int yk) {
	n.clear();char a=chess[xi][yi],b=chess[xj][yj],c=chess[xk][yk];
	++n[a];++n[b];++n[c];
	if(n[a]==1&&n[b]==1)	return;
	if(n[a]==1) {
		if(a>b)	swap(a,b);
		if(!m[std::make_pair(a,b)]) {
			m[std::make_pair(a,b)]=true;++group;
		}
	}
	else if(n[a]==2) {
		if(a>b)	swap(a,b);
		if(!m[std::make_pair(a,b)]) {
			m[std::make_pair(a,b)]=true;++group;
		}
	}
	else {
		if(!m[std::make_pair(a,b)]) {
			m[std::make_pair(a,b)]=true;++person;
		}
	}
}

int main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<4;++i) scanf("%s",chess[i]+1);
	check(1,1,1,2,1,3);check(2,1,2,2,2,3);check(3,1,3,2,3,3);
	check(1,1,2,1,3,1);check(1,2,2,2,3,2);check(1,3,2,3,3,3);
	check(1,1,2,2,3,3);check(3,1,2,2,1,3);
	printf("%d\n%d\n",person,group);
	return 0;
}
