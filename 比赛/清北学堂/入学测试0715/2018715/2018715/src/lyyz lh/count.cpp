#include <bits/stdc++.h>
using namespace std;

int dui[9999];int a[5][5];
void heng(int p,int l)
{
	if ((a[p][l] == a[p + 1][l]) && (a[p + 1][l] == a[p + 2][l]))
	{
	dui[a[p][l]]++;
	}
	else if (((a[p][l] == a[p + 1][l]) && (a[p + 1][l] != a[p + 2][l])) || ((a[p + 1][l] == a[p + 2][l]) && (a[p + 1][l] != a[p][l])))
	{	
	if ((a[p][l] != a[p + 2][l])) {dui[a[p][l]]++;dui[a[p + 2][l]]++;}
	if ((a[p][l] != a[p + 1][l])) {dui[a[p][l]]++;dui[a[p + 1][l]]++;}
	}
}
void shu(int p,int l)
{
	if ((a[p][l] == a[p][l + 1]) && (a[p][l + 1] == a[p][l + 2]))
	{
	dui[a[p][l]]++;
	}
	else if (((a[p][l] == a[p][l + 1]) && (a[p][l + 1] != a[p][l + 2])) || ((a[p][l + 1] == a[p][l + 2] && (a[p][l] != a[p][l + 1]))))
	{	
	if ((a[p][l] != a[p][l + 1])) {dui[a[p][l]]++;dui[a[p][l + 1]]++;}
	if ((a[p][l] != a[p][l + 2])) {dui[a[p][l]]++;dui[a[p][l + 2]]++;}
	}
}
int main()
{
	freopen("cout.in","r",stdin);
	freopen("count.out","w",stdout);
	int ansmen,ansdui;
	memset (a,0,sizeof(a));
	memset (dui,0,sizeof(dui));

	for (int i = 1;i <= 3;i++)
	 for (int j = 1;j <= 3;j++)
	 scanf("%d",a[i][j]);
	for (int l = 1;l <= 3;l++) heng(1,l);
	for (int p = 1;p <= 3;p++) shu(p,1);
	if ((a[1][1] == a[2][2]) && (a[2][2] == a[3][3])) 
	{
		dui[a[1][1]]++;
	}
	if ((a[1][1] == a[2][2]) && (a[1][1] != a[3][3])) {dui[a[1][1]]++;dui[a[3][3]]++;}
	if ((a[1][1] != a[2][2]) && (a[1][1] == a[3][3])) {dui[a[1][1]]++;dui[a[2][2]]++;}
	if ((a[1][3] == a[2][2]) && (a[2][2] == a[3][1])) 
	{
		dui[a[1][3]]++;
	}
	if ((a[1][3] == a[2][2]) && (a[1][3] != a[3][1])) {dui[a[1][3]]++;dui[a[3][1]]++;}
	if ((a[1][3] != a[2][2]) && (a[1][3] == a[3][1])) {dui[a[1][3]]++;dui[a[2][2]]++;}
	for (int i = 1;i <= 1000;i++)
	{
	ansmen += dui[i]; 	
	while (dui[i] >= 2) ansdui++;
	}
	cout << ansmen << endl;
	cout << ansdui << endl;
}
