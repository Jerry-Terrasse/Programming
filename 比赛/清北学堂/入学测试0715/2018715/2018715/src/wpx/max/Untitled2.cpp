#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100000;
int xi,b=0,z,qz=0;
double ju,shi;
int ah[maxn],bh[maxn],sum=0,bt[maxn],av,bv,l,n,xh[maxn],ci;
void suan()
{
		if(z<l){
			while(z<l){
				z++;
				if(xh[z]>b)b=xh[z];
			} 
		}
	if(ju=l)return ;
	bt[z]=(z-qz)*bv;
	ju=z-qz-double(bt[z]/av);
	shi=ju*av;
	sum+=shi*b;
	qz=z;
	b=0;
	suan();
}
int main(){
	freopen("max","in",stdin);
	freopen("max","out",stdout);
	cin>>l>>n>>av>>bv;
	for(int i=1;i<=n;i++){
		cin>>xi>>ci;
		xh[xi]=ci;
		if(b<xh[xi]){
			b=xh[xi];
			z=xi;
		}
	}
	bt[z]=(z-qz)*bv;
	ju=z-qz-double(bt[z]/av);
	shi=ju*av;
	sum+=shi*b;
	qz=z;
	b=0;
	suan();
	cout<<sum;
	return 0;
}
