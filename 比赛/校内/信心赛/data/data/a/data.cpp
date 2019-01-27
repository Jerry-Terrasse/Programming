#include <bits/stdc++.h>

using namespace std ;

int main() { 

		freopen(".cnt", "r", stdin) ; 
		int kkk ;
		scanf("%d", &kkk) ;

		srand(time(0) + kkk * 10000) ;

		int T = 5 ; 
		printf("%d\n", T) ; 
		T -- ; 
		while (T --) { 
			int n = rand() % 20 + 2981 ; 
			int m = rand() % 2 + 2999 ; 

			printf("%d %d\n", n, m) ; 

			while (m --) { 
					int l = rand() % (n - 1) + 1 ;
					int r = rand() % (n - l) + l + 1; 
					printf("%d %d\n", l, r) ; 
			}
		}

		int n = 3000 ; 
		int m = 3000 ; 
			
		printf("%d %d\n", n, m );  
		for (int i = 1; i < 1500; i ++) printf("%d %d\n", i, 1500) ;
		for (int i = 1501; i < 3000; i ++) printf("%d %d\n", 1500, i) ;
		printf("%d %d\n", 1, 3000) ; 
	    printf("%d %d\n", 1499, 3000) ; 
		freopen(".cnt", "w", stdout) ; 

	
		printf("%d\n", kkk + rand()) ; 
}
