#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
ifstream fin("count.in");
ofstream fout("count.out");
int n;
int a[4][4],ansr=0,ansd=0;
int main()
{
	ios::sync_with_stdio(false);
	string s1,s2,s3;
	fin>>s1>>s2>>s3;
	for(int i=0;i<3;i++) a[0][i]=s1[i]-0;
	for(int i=0;i<3;i++) a[1][i]=s2[i]-0;
	for(int i=0;i<3;i++) a[2][i]=s3[i]-0;
	for(int i=0;i<3;i++)
		if(a[i][0]==a[i][1]&&a[i][1]==a[i][2]) ansr++;
		else if(a[i][0]==a[i][1]||a[i][1]==a[i][2]||a[i][0]==a[i][2]) ansd++;
	for(int i=0;i<3;i++)
		if(a[0][i]==a[1][i]&&a[1][i]==a[2][i]) ansr++;
		else if(a[0][i]==a[1][i]||a[1][i]==a[2][i]||a[0][i]==a[2][i]) ansd++;	
	if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]) ansr++;
	else if(a[0][0]==a[1][1]||a[1][1]==a[2][2]||a[0][0]==a[2][2]) ansd++;	
	if(a[0][2]==a[1][1]&&a[1][1]==a[2][0]) ansr++;
	else if(a[2][0]==a[1][1]||a[1][1]==a[0][2]||a[2][0]==a[0][2]) ansd++;	
	fout<<ansr<<'\n'<<ansd;
	return 0;
}
