#include<cstdio>
#include<bitset>
using namespace std;
const char w[6]={20,10,5,3,2,1};
char c='\0';
bitset<1001>bts;
inline void read(short&);
void write(const short&);
int main()
{
  register char i=6;
	register short a=0;
  for(bts[0]=1;i--;)
  {
  	read(a);
  	for(;a--;bts|=bts<<w[i]);
	}
	printf("Total=");
	write(bts.count()-1);
	return 0;
}
void write(const short &x)
{
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10^48);
	return;
}
inline void read(short &x)
{
	for(x=0,c=getchar();c>='0'&&c<='9';c=getchar())
	{
		x=(x<<1)+(x<<3)+(c^48);
	}
	return;
}
