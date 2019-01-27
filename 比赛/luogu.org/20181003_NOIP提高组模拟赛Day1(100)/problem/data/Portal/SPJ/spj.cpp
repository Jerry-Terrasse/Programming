#include<bits/stdc++.h>
#define qread(x) x=read()
#define random(x) rand()%x 
#define mes(x,y) memset(x,y,sizeof(x))
#define mpy(x,y) memcpy(x,y,sizeof(x))
#define Maxn 100
#define Maxchar 128
#define Point 5
#define INF 2147483647
FILE *InAns,*OutUser,*OutAns,*Out,*Err;
int n,m,sum,a[Maxn+1],b[Maxn+1],c[Maxn+1],Ans[2];
int main(int argc,char *argv[]){
    InAns=fopen("Portal.in","r");
    OutUser=fopen("Portal.out","r");
    OutAns=fopen("Portal.ans","r");
    Err=fopen("spj.out","w");
    fscanf(OutUser,"%d",&Ans[0]);
	fscanf(OutAns,"%d",&Ans[1]);
    if(Ans[0]==Ans[1]){
    	fscanf(InAns,"%d",&n);
    	for(int i=1;i<=n;i++)fscanf(InAns,"%d%d%d",&a[i],&b[i],&c[i]);
    	fscanf(OutUser,"%d",&m);
    	sum=0;
		for(int i=1;i<=m;i++){
			fscanf(OutUser,"%d",&a[i]);
			sum+=c[a[i]];
		} 
    	if(sum==Ans[1]){
    		fprintf(Err,"The answer is correct\n");
    		return 0;
		}
		else{
    		fprintf(Err,"Sum is£º%d But you:%d\n",Ans[1],sum);
			return 0;
		}
    }
    else{
    	fprintf(Err,"Ans is£º%d But you:%d\n",Ans[1],Ans[0]);
    	return 0;
    }
}
