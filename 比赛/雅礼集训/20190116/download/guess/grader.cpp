#include"guess.h"
#include<string>
#include<stdio.h>
#include<iostream> 
using namespace std;
typedef unsigned long long u64;
static struct random_t{
	u64 s0,s1;
	random_t(){s0=2,s1=3;}
	random_t(u64 s0,u64 s1):s0(s0),s1(s1){}
	u64 get(){
		std::swap(s0,s1);
		s1^=s1<<23,s1^=(s1>>17)^s0^(s0>>26);
		return s0+s1;
	}
	int randint(int L,int R){
		return get()%(R-L+1)+L;
	}
}rnd;
static const int N=1000,M=N+5;
static string S;
static int cnt[M],qcnt;
static bool asked[M][M];
void ensure(bool True,const char *Message){
	if(!True){
		printf("%s\n",Message);
		exit(-1);
	}
}
int query(int l,int r){
	ensure(l<=r,"Invalid Query: not a range");
	ensure(0<=l&&r<N,"Invalid Query: index out of range");
	ensure(!asked[l][r],"Invalid Query: asked before");
	++qcnt,asked[l][r]=true;
	if(rnd.randint(0,1))return cnt[r+1]-cnt[l];
	int res=rnd.randint(0,r-l);
	return res+(res>=cnt[r+1]-cnt[l]);
}
int main(){
	int Test;
	for(cin>>Test;Test;--Test){
		cin>>S;
		for(int i=0;i<N;++i)ensure(S[i]=='0'||S[i]=='1',"Invalid Input");
		ensure(S.length()==N,"Invalid Input");
		cin>>rnd.s0>>rnd.s1; 
		for(int i=0;i<N;++i)cnt[i+1]=(S[i]=='1')+cnt[i];
		ensure(guess()==S,"Wrong Answer");
		printf("Accepted Answer: %d queries used",qcnt);
	}
}
