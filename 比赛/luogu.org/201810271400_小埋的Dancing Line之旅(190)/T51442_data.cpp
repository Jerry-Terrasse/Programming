#include<iostream>
#include<ctime>
#include<cstdlib>
//#define MAXN 100010
#define MAXN 1000010
#define rr(x) (rand()*rand()%(x))
using namespace std;
int main()
{
	int i=0;
	srand(time(NULL));
	cout<<rr(MAXN)+1<<' '<<rr(MAXN)+1<<' '<<rr(MAXN)+1<<endl;
	return 0;
}
