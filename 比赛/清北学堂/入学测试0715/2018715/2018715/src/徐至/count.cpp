#include<iostream>
#include<cstdio>
using namespace std;
char a[5][5];
char a1[37],a2[100000],b2[100000];
int num1,num2;
char aa,bb,cc;
int ans1,ans2;//1->人   2->队 
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i=1;i<=3;i++)
	    for(int j=1;j<=3;j++){
	    	cin>>a[i][j];
		}
	//人 
	for(int i=1;i<=3;i++){
		if(a[i][1]==a[i][2]&&a[i][2]==a[i][3]) {
			int aa=ans1;
		    for(int j=1;j<=num1;j++){
			    if(a1[j]==a[i][1]) aa--;
			} 
		if(aa==ans1){
			ans1++;
			a1[++num1]=a[i][1];
		}
	}
		if(a[1][i]==a[2][i]&&a[3][i]==a[2][i]) {
			int aa=ans1;
		    for(int j=1;j<=num1;j++){
			    if(a1[j]==a[1][i]) aa--;
			} 
		if(aa==ans1){
			ans1++;
			a1[++num1]=a[i][1];
		}
	}
	}
	if(a[1][1]==a[2][2]&&a[2][2]==a[3][3])  {
			int aa=ans1;
		    for(int j=1;j<=num1;j++){
			    if(a1[j]==a[1][1]) aa--;
			} 
		if(aa==ans1){
			ans1++;
			a1[++num1]=a[1][1];
		}
	}
	if(a[1][3]==a[2][2]&&a[2][2]==a[3][1])  {
			int aa=ans1;
		    for(int j=1;j<=num1;j++){
			    if(a1[j]==a[2][2]) aa--;
			} 
		if(aa==ans1){
			ans1++;
			a1[++num1]=a[1][3];
		}
	}
	//队
	for(int i=1;i<=3;i++){
		aa=a[1][i];bb=a[2][i];cc=a[3][i];
		if(aa==bb&&aa!=cc) {
		    int w=ans2;
		    if(aa>cc) swap(aa,cc);//小，大 
			for(int j=1;j<=num2;j++){
				if(a2[j]==aa&&b2[j]==cc) w--;
			}
			if(w==ans2){
				ans2++;
				a2[++num2]=aa;b2[num2]=cc;
			}
	    }
	    if(aa==cc&&aa!=bb) {
		    int w=ans2;
		    if(aa>bb) swap(aa,bb);//小，大 
			for(int j=1;j<=num2;j++){
				if(a2[j]==aa&&b2[j]==bb) {
				    w--;
				}
			}
			if(w==ans2){
				ans2++;
				a2[++num2]=aa;b2[num2]=bb;
			}
	    }
	    if(bb==cc&&aa!=cc) {
		    int w=ans2;
		    if(aa>cc) swap(aa,cc);//小，大 
			for(int j=1;j<=num2;j++){
				if(a2[j]==aa&&b2[j]==cc) w--;
			}
			if(w==ans2){
				ans2++;
				a2[++num2]=aa;b2[num2]=cc;
			}
	    }
	
		aa=a[i][1];bb=a[i][2];cc=a[i][3];
		if(aa==bb&&aa!=cc) {
		    int w=ans2;
		    if(aa>cc) swap(aa,cc);//小，大 
			for(int j=1;j<=num2;j++){
				if(a2[j]==aa&&b2[j]==cc) w--;
			}
			if(w==ans2){
				ans2++;cout<<"4"<<endl;
				a2[++num2]=aa;b2[num2]=cc;
			}
	    }
	    if(aa==cc&&aa!=bb) {
		    int w=ans2;
		    if(aa>bb) swap(aa,bb);//小，大 
			for(int j=1;j<=num2;j++){
				if(a2[j]==aa&&b2[j]==bb) w--;
			}
			if(w==ans2){
				ans2++;
				a2[++num2]=aa;b2[num2]=bb;
			}
	    }
	    if(bb==cc&&aa!=cc) {
		    int w=ans2;
		    if(aa>cc) swap(aa,cc);//小，大 
			for(int j=1;j<=num2;j++){
				if(a2[j]==aa&&b2[j]==cc) w--;
			}
			if(w==ans2){
				ans2++;
				a2[++num2]=aa;b2[num2]=cc;
			}
	    }
	
	} 
	aa=a[1][1];bb=a[2][2];cc=a[3][3];
			if(aa==bb&&aa!=cc) {
		    int w=ans2;
		    if(aa>cc) swap(aa,cc);//小，大 
			for(int j=1;j<=num2;j++){
				if(a2[j]==aa&&b2[j]==cc) w--;
			}
			if(w==ans2){
				ans2++;
				a2[++num2]=aa;b2[num2]=cc;
			}
	    }
	    if(aa==cc&&aa!=bb) {
		    int w=ans2;
		    if(aa>bb) swap(aa,bb);//小，大 
			for(int j=1;j<=num2;j++){
				if(a2[j]==aa&&b2[j]==bb) w--;
			}
			if(w==ans2){
				ans2++;
				a2[++num2]=aa;b2[num2]=bb;
			}
	    }
	    if(bb==cc&&aa!=cc) {
		    int w=ans2;
		    if(aa>cc) swap(aa,cc);//小，大 
			for(int j=1;j<=num2;j++){
				if(a2[j]==aa&&b2[j]==cc) w--;
			}
			if(w==ans2){
				ans2++;
				a2[++num2]=aa;b2[num2]=cc;
			}
	    }
	 
	    aa=a[1][3];bb=a[2][2];cc=a[3][1];
			if(aa==bb&&aa!=cc) {
		    int w=ans2;
		    if(aa>cc) swap(aa,cc);//小，大 
			for(int j=1;j<=num2;j++){
				if(a2[j]==aa&&b2[j]==cc) w--;
			}
			if(w==ans2){
				ans2++;
				a2[++num2]=aa;b2[num2]=cc;
			}
	    }
	    if(aa==cc&&aa!=bb) {
		    int w=ans2;
		    if(aa>bb) swap(aa,bb);//小，大 
			for(int j=1;j<=num2;j++){
				if(a2[j]==aa&&b2[j]==bb) w--;
			}
			if(w==ans2){
				ans2++;
				a2[++num2]=aa;b2[num2]=bb;
			}
	    }
	    if(bb==cc&&aa!=cc) {
		    int w=ans2;
		    if(aa>cc) swap(aa,cc);//小，大 
			for(int j=1;j<=num2;j++){
				if(a2[j]==aa&&b2[j]==cc) w--;
			}
			if(w==ans2){
				ans2++;
				a2[++num2]=aa;b2[num2]=cc;
			}
	    }
	 
	cout<<ans1<<endl<<ans2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
