#include<iostream>
#define ok(x,y) (!((x)*(y)%((x)+(y))))
using namespace std;
long long n=0,cnt=0;
int main() {
	register int i=0,j=0;
	//++n;cnt=0;
	/*cout<<n<<'=';
	for(j=n,i=2;j>1;++i)
	{
		for(;!(j%i);j/=i)
		{
		  cout<<i<<'*';
	}
	}
	cout<<':';*/
	for(n=1;; ++n) {
		cnt=0;
		for(i=1; i<n*n; ++i) {
			if(ok(i,n*n-i)) {
				cout<<i<<' '<<(n*n)-i<<endl;
				++cnt;
			}
			/*for(j=1;j+i<=n;++j)
			{
			  if(!(i*j%(i+j)))
			  {
			    cout<<i<<' '<<j<<endl;
			  }
			}*/
		}
		if(cnt+1==n)
		{
			cout<<n<<":YES"<<endl;
		}
		else
		{
			system("pause");
		}
	}
	//cout<<cnt<<endl;
	//main();
	return 0;
}
