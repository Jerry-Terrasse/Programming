#include <iostream>
#include <cstdio>

int ans1,ans2;
char s[4][4];
bool h1[27],h2[27][27];

bool pd(bool *a,char c){
	return a[(int)(c - 'A')] == false;
}

bool pd2(char a,char c){
	if(h2[(int)(a - 'A')][(int)(c - 'A')] == false &&h2[(int)(c - 'A')][(int)(a - 'A')]== false)return true;
	else return false; 
}

int main(int argc,char *argv[]){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i = 1;i <= 3;i++){
		for(int j = 1;j <= 3;j++){
			std::cin>>s[i][j];
		}
	}
	for(int i = 1;i <= 3;i++){
		if(s[i][1] == s[i][2]&&s[i][1] == s[i][3]){
			if(pd(h1,s[i][1])){
				h1[(int)(s[i][1] - 'A')] = true;
				ans1++;
			}
		}
		else if(s[i][1] == s[i][2] && s[i][1] != s[i][3]){
			if(pd2(s[i][1],s[i][2])){
				h2[(int)(s[i][1] - 'A')][(int)(s[i][2] - 'A')] = true;
				h2[(int)(s[i][2] - 'A')][(int)(s[i][1] - 'A')] = true;
				ans2++;
			}
		}
		else if(s[i][1] == s[i][3] && s[i][1] != s[i][2]){
			if(pd2(s[i][1],s[i][3])){
				h2[(int)(s[i][1] - 'A')][(int)(s[i][3] - 'A')] = true;
				h2[(int)(s[i][3] - 'A')][(int)(s[i][1] - 'A')] = true;
				ans2++;
			}
		}
		else if(s[i][3] == s[i][2] && s[i][1] != s[i][3]){
			if(pd2(s[i][3],s[i][2])){
				h2[(int)(s[i][3] - 'A')][(int)(s[i][2] - 'A')] = true;
				h2[(int)(s[i][2] - 'A')][(int)(s[i][3] - 'A')] = true;
				ans2++;
			}
		}
	}
	for(int i = 1;i <= 3;i++){
		if(s[1][i] == s[2][i] &&s[1][i] == s[3][i]){
			if(pd(h1,s[1][2])){
				h1[(int)(s[1][i] - 'A')] = true;
				ans1++;
			}
		}
		else if(s[1][i] == s[2][i] && s[1][i] != s[3][i]){
			if(pd2(s[1][i],s[2][i])){
				h2[(int)(s[1][i] - 'A')][(int)(s[2][i] - 'A')] = true;
				h2[(int)(s[2][i] - 'A')][(int)(s[1][i] - 'A')] = true;
				ans2++;
			}
		}
		else if(s[1][i] == s[3][i] && s[1][i] != s[2][i]){
			if(pd2(s[1][i],s[3][i])){
				h2[(int)(s[1][i] - 'A')][(int)(s[3][i] - 'A')] = true;
				h2[(int)(s[3][i] - 'A')][(int)(s[1][i] - 'A')] = true;
				ans2++;
			}
		}
		else if(s[2][i] == s[3][i] && s[1][i] != s[2][i]){
			if(pd2(s[2][i],s[3][i])){
				h2[(int)(s[2][i] - 'A')][(int)(s[3][i] - 'A')] = true;
				h2[(int)(s[3][i] - 'A')][(int)(s[2][i] - 'A')] = true;
				ans2++;
			}
		}
	}
	if(s[1][1] == s[2][2] &&s[1][1] == s[3][3]){
		if(pd(h1,s[1][1])){
			h1[(int)(s[1][1] - 'A')] = true;
			ans1++;
		}
	}
	if(s[1][3] == s[2][2] && s[1][3] == s[3][1]){
		if(pd(h1,s[1][3])){
			h1[(int)(s[1][3] - 'A')] = true;
			ans1++;
		}
	}
	if(s[1][1] == s[2][2] && s[1][1] != s[3][3]){
		if(pd2(s[1][1],s[2][2])){
			h2[(int)(s[1][1] - 'A')][(int)(s[2][2] - 'A')] = true;
			h2[(int)(s[2][2] - 'A')][(int)(s[1][1] - 'A')] = true;
			ans2++;
		}
	}
	if(s[1][1] == s[3][3] && s[1][1] != s[2][2]){
		if(pd2(s[1][1],s[3][3])){
			h2[(int)(s[1][1] - 'A')][(int)(s[3][3] - 'A')] = true;
			h2[(int)(s[3][3] - 'A')][(int)(s[1][1] - 'A')] = true;
			ans2++;
		}
	}
	if(s[3][3] == s[2][2] && s[1][1] != s[3][3]){
		if(pd2(s[3][3],s[2][2])){
			h2[(int)(s[3][3] - 'A')][(int)(s[2][2] - 'A')] = true;
			h2[(int)(s[2][2] - 'A')][(int)(s[3][3] - 'A')] = true;
			ans2++;
		}
	}
	if(s[1][3] == s[2][2] && s[1][3] != s[3][1]){
		if(pd2(s[1][3],s[2][2])){
			h2[(int)(s[1][3] - 'A')][(int)(s[2][2] - 'A')] = true;
			h2[(int)(s[2][2] - 'A')][(int)(s[1][3] - 'A')] = true;
			ans2++;
		}
	}
	if(s[3][1] == s[2][2] && s[3][1] != s[1][3]){
		if(pd2(s[3][1],s[2][2])){
			h2[(int)(s[3][1] - 'A')][(int)(s[2][2] - 'A')] = true;
			h2[(int)(s[2][2] - 'A')][(int)(s[3][1] - 'A')] = true;
			ans2++;
		}
	}
	if(s[1][3] == s[3][1] && s[1][3] != s[2][2]){
		if(pd2(s[1][3],s[3][1])){
			h2[(int)(s[1][3] - 'A')][(int)(s[3][1] - 'A')] = true;
			h2[(int)(s[3][1] - 'A')][(int)(s[1][3] - 'A')] = true;
			ans2++;
		}
	}
	printf("%d\n%d\n",ans1,ans2);
	return 0;
}
