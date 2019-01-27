#include <bits/stdc++.h>

#define Rand() ((rand() << 15) | rand())

using namespace std ;

int main() { 

		freopen(".cnt", "r", stdin) ; 
		int kkk ;
		scanf("%d", &kkk) ;

		srand(time(0) + kkk * 10000) ;

		int n = rand() % 10 + 499991 ; 
		int m = rand() % 10 + 499991; 
		printf("%d %d\n", n, m ) ;

		for (int i = 1; i <= n + m; i ++) {
				printf("%d %d\n", Rand() % 500000 + 1, Rand() % 500000 + 1) ; 
		}

		freopen(".cnt", "w", stdout) ; 

	
		printf("%d\n", kkk + rand()) ; 
}

