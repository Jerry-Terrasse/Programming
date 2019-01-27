#include <iostream>
#include <cstdio>
#include <algorithm>

int n, k, x, y;
int lis[200005];
//bool lia[200005];

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= 2 * n - 1; i = i + 2){
		std :: cin >> x >> y;
		lis[i] = x;
		lis[i + 1] = y;
	}

	/*for(int i = 1; i <= 2 * n; i = i + 2){	
		for(int j = 1; j <= 2 * n; j = j + 2){
			if(lis[i] <= lis[j] && lis[i + 1] >= lis[j + 1]) {
				lia[j] = 1;
				lia[j + 1] = 1;
			}
			
		}
	}*/
	
	std::sort(lis + 1,lis + 2*n + 1);
	std::cout << lis[2*n] - lis[1] << std::endl;
	
	freopen("max.in","r" ,stdin);
	freopen("max.out","r",stdout);	
	
	return 0;
}
