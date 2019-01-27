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
int n,m,a[Maxn+1],b[Maxn+1],c[Maxn+1],d[Maxn+1],map[Maxn+1][Maxn+1];
char Ans[2][Maxchar+1];
int main(int argc,char *argv[]){
    InAns=fopen("War.in","r");
    OutUser=fopen("War.out","r");
    OutAns=fopen("War.ans","r");
    Err=fopen("spj.out","w");
    fscanf(OutUser,"%s",Ans[0]+1);
	fscanf(OutAns,"%s",Ans[1]+1);
    if(strcmp(Ans[0]+1,Ans[1]+1)==0){
    	if(strcmp(Ans[0]+1,"NO")==0){	
	    	fprintf(Err,"The ans is correct\n");
    		return 0;
    	}
    	else{
    		fscanf(InAns,"%d%d",&n,&m);
    		for(int i=1;i<=n;i++)fscanf(InAns,"%d",&a[i]);
    		for(int i=1;i<=n;i++)fscanf(InAns,"%d",&d[i]);
    		mes(map,false);
			for(int i=1;i<=m;i++){
				int x,y;
				fscanf(InAns,"%d%d",&x,&y);
				map[x][y]=map[y][x]=true;
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					int x;
    				fscanf(OutUser,"%d",&x);
    				if(x>0){
	    				if(map[i][j]==true||i==j){
	    					b[i]+=x;
	    					c[j]+=x;
	    				}
	    				else{
	    					fprintf(Err,"%d can't conn %d\n",i,j);
	    					return 0;
	    				}
	    			}
				}
			}
			for(int i=1;i<=n;i++){
				if(b[i]>a[i]){
					fprintf(Err,"%d can't sent %d to other\n",i,b[i]);
					return 0;
				}
				if(a[i]-b[i]+c[i]!=d[i]){
					fprintf(Err,"%d can't save %d\n",i,d[i]);
					return 0;
				}
			}
	    	fprintf(Err,"The ans is correct\n");
    		return 0;
		}
    }
    else{
    	fprintf(Err,"Ans is£º%s But you:%s\n",Ans[1]+1,Ans[0]+1);
    	return 0;
    }
}
