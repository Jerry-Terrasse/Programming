#include"matrix.h"
#include<vector>
void findMatrix(int N){
	for(int S=0;S<1<<N*N;++S){
		int i,j;
		std::vector<std::vector<char>>G(N,std::vector<char>(N));
		for(i=0;i<N;++i)for(j=0;j<N;++j)G[i][j]=(S>>(i*N+j)&1)+'0';
		if(isSubMatrix(G))foundMatrix(G);
	}
	throw "GG";
}
