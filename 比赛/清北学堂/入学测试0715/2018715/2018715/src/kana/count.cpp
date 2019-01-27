#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <utility> 
using namespace std;

int ans1,ans2;
char a[5][5];


void work_ans1();
void work_ans2();

int main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	for(int i = 1;i <= 3;++i)
		for(int j = 1;j <= 3;++j)
			cin >>a[i][j];
	work_ans1();
	work_ans2();
	printf("%d\n%d",ans1,ans2);
	return 0;
}
void work_ans1() {
	map <char , bool > flag;
	for(int i = 1;i <= 3;++i) {
		if(a[1][i] == a[2][i] && a[2][i] == a[3][i] && !flag[a[1][i]]) {
			flag[a[1][i]] = true;
			ans1++;
		}
		if(a[i][1] == a[i][2] && a[i][2] == a[i][3] && !flag[a[1][i]]) {
			flag[a[i][1]] = true;
			ans1++;
		}
	}
	if(a[1][1] == a[2][2] && a[2][2] == a[3][3] && !flag[a[1][1]]) {
		flag[a[1][1]] = true;
		ans1++;
	}
	if(a[3][1] == a[2][2] && a[2][2] == a[1][3] && !flag[a[3][1]]) {
		flag[a[3][1]] = true;
		ans1++;
	}
}
void work_ans2() {
	map <char ,bool > m;
	for(int i = 1;i <= 3;++i) {
		m[a[i][1]] = true;
		m[a[i][2]] = true;
		m[a[i][3]] = true;
		if(m.size() == 2) {
			
			ans2++;
		}
		m.erase(m.begin(),m.end()); 
	}
	m[a[1][1]] = true;
	m[a[2][2]] = true;
	m[a[3][3]] = true;
	if(m.size() == 2) {
		
		ans2++;
	}
	m.erase(m.begin(),m.end());
	m[a[3][1]] = true;
	m[a[2][2]] = true;
	m[a[1][3]] = true;
	if(m.size() == 2) ans2++;
	m.erase(m.begin(),m.end());
}
