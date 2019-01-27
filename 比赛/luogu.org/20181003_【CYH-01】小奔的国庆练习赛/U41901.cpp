#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;
int cnt=0;
char c='\0';
inline int rr(int);
int main()
{
	int i=0;
	srand(time(NULL));
	for(c=getchar();c!='\n';c=getchar())
	{
		if(c=='*')
		{
			cnt++;
		}
	}
	if(cnt==0)
	{
		putchar(rr(9)+'1');
		putchar(rr(10)+'0');
		putchar('.');
		putchar(rr(10)+'0');
		putchar(rr(10)+'0');
	}
	else if(cnt==1)
	{
		printf("4.50");
	}
	else if(cnt==2)
	{
		printf("45.00");
	}
	else if(cnt==3)
	{
		printf("450.00");
	}
	else
	{
		printf("%.2f",(float)pow(10,cnt-1)*4.5);
	}
	return 0;
}
inline int rr(int x)
{
	return rand()%x;
}
