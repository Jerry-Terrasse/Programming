#include<bits/stdc++.h>
#define MAXN 13
using namespace std;
int pad[MAXN][MAXN],n=0,t=0;
ofstream fout;
int rr(int);
int main()
{
  int i=0,j=0;
	for(;;t++)
  {
	srand(time(NULL));
  	cout<<"Running on No."<<t<<endl;
		memset(pad,0,sizeof(pad));
  	n=rr(MAXN-1);
  	//n=12;
		j=rr(n*n+1);
		for(i=0;i<j;i++)
		{
			pad[rr(n)][rr(n)]=1;
		}
		fout.open("data.in");
		fout<<n<<endl;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
			  if(pad[i][j])
			  {
			  	fout<<'.';
			  	//cout<<'.';
				}
				else
				{
					fout<<'*';
					//cout<<'*';
				}
			}
			fout<<endl;
			//cout<<endl;
		}
		fout.close();
		system("P1562.exe <data.in >fast.out");
		system("old.exe <data.in >slow.out");
		//system("pause");
		if(system("fc fast.out slow.out"))
		{
			cout<<"WA on No."<<t<<endl;
			system("pause");
		}
		else
		{
			cout<<"Accepted"<<endl;
		}
	}
	return 0;
}
int rr(int x)
{
	return rand()*rand()%x+1;
}
