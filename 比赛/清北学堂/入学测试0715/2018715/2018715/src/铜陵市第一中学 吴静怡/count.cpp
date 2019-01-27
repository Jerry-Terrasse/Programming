#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<fstream>
using namespace std;
char a[100][100];
int s1,s2;
int main(){
	int i,j;
	int temp;
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(i=1;i<=3;i++)
	   for(j=1;j<=3;j++)
	   cin>>a[i][j];
	for(i=1;i<=3;i++){
	    temp=0;
	   for(j=1;j<=2;j++){	
	       if(a[i][j]!=a[i][j+1]) temp++;
	       if(j==2&&temp==2&&a[i][j+1]==a[i][j-1]) temp--;
	   }
	   if(temp==1) s2++;
	   if(temp==0) s1++;
    }
    for(i=1;i<=3;i++){
    	temp=0;
    	for(j=1;j<=2;j++){
		if(a[j+1][i]!=a[j][i]) temp++;
		if(j==2&&a[j-1][i]==a[j+1][i]&&temp==2) temp--;
		}
         if(temp==0) s1++;
         if(temp==1) s2++;	
	}
       
    temp=0;
    for(i=1;i<=2;i++){
	if(a[i][i]!=a[i+1][i+1]) temp++;
	if(i==2&&a[i+1][i+1]==a[i-1][i-1]&&temp==2) temp--;
	}
       
       if(temp==1) s2++;
	   if(temp==0) s1++;
	temp=0;
	for(i=1;i<=2;i++){
	if(a[i+1][3-i]!=a[i][4-i]) temp++;
	if(i==2&&a[i+1][3-i]==a[i-1][5-i]&&temp==2) temp--;
	}
	   
	   if(temp==1) s2++;
	   if(temp==0) s1++;
	   cout<<s1<<endl;
	   cout<<s2<<endl;
	   return 0;
 
}
