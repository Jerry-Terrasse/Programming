#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
map<char,int>wg;
char a[10][10];
int d[30],s[30][30],ansa=0,ansb=0;
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
    memset(a,0,sizeof(a));
    for(char i='A';i<='Z';i++)wg[i]=i-'A'+1;
    cin>>a[1];
    getchar();
    for(int i=2;i<=3;i++){
        cin>>a[i];
        getchar();
    }
    for(int i=1;i<=3;i++){
        char xdd1=a[i][0],xdd2;
        int mgg=1;
        for(int j=1;j<3;j++){
            if(mgg==2){
                if(a[i][j]!=xdd1&&a[i][j]!=xdd2){
                    mgg++;
                    break;
                }
            }
            if(mgg==1){
                if(a[i][j]!=xdd1){
                    xdd2=a[i][j];
                    mgg++;
                }
            }
        }
        if(mgg==1)d[wg[xdd1]]=1;
        if(mgg==2)s[wg[xdd1]][wg[xdd2]]=1;
    }
    for(int i=0;i<=2;i++){
        char xdd1=a[1][i],xdd2;
        int mgg=1;
        for(int j=2;j<=3;i++){
            if(mgg==2){
                if(a[j][i]!=xdd1&&a[j][i]!=xdd2){
                    mgg++;
                    break;
                }
            }
            if(mgg==1){
                if(a[j][i]!=xdd1){
                    xdd2=a[j][i];
                    mgg++;
                }
            }
        }
        if(mgg==1)d[xdd1]=1;
        if(mgg==2)s[xdd1][xdd2]=1;
    }
    char xdd1=a[1][0],xdd2;
    int mgg=1;
    for(int i=2;i<=3;i++){
        if(mgg==2){
            if(a[i][i-1]!=xdd1&&a[i][i-1]!=xdd2){
                mgg++;
                break;
            }
        }
        if(mgg==1){
            if(a[i][i-1]!=xdd1){
                xdd2=a[i][i-1];             
                mgg++;
            }
        }
    }
    if(mgg==1)d[wg[xdd1]]=1;
    if(mgg==2)s[wg[xdd1]][wg[xdd2]]=1;
    xdd1=a[1][2];
    mgg=1;
        for(int i=2;i<=3;i++){
        if(mgg==2){
            if(a[i][3-i]!=xdd1&&a[i][3-i]!=xdd2){
                mgg++;
                break;
            }
        }
        if(mgg==1){
            if(a[i][3-i]!=xdd1){
                xdd2=a[i][3-i];             
                mgg++;
            }
        }
    }
    if(mgg==1)d[wg[xdd1]]=1;
    if(mgg==2)s[wg[xdd1]][wg[xdd2]]=1;
    for(int i=1;i<=26;i++)if(d[i]==1)ansa++;
    for(int i=1;i<=26;i++){
        for(int j=1;j<=26;j++){
            if(s[i][j]==1)ansb++;
           }
       }
    cout<<ansa<<endl<<ansb;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
