#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("cover.in","r",stdin);
	freopen("cover.out","w",stdout);
	int m , n ;
	int jishu = 0 ;
	int big,small ;
	cin >> m >> n ;
	for(int i = 1 ; i <= m ; i++){
		cin >> small >> big ;
		jishu = max(big-small,jishu);
	}
	cout << jishu ;
}
