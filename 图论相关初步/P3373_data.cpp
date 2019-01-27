#include<bits/stdc++.h>
#define MAXN 100000
#define ll long long
using namespace std;
int t=0,n=0,m=0,p=0,a=0,o=0,x=0,y=0;
long double start=0,end=0;
long double llf=0,total=332000.771;
int rr(int);
ofstream fout;
int main()
{
  int i=0;
  srand(time(NULL));
  for(t=400;;t++)
  {
  	//system("pause");
		cout<<endl<<"No."<<t<<"::"<<endl;
		fout.open("data.in");
	  n=rr(MAXN);
  	m=rr(MAXN);
  	p=rr(MAXN);
  	fout<<n<<' '<<m<<' '<<p<<endl;
  	for(i=0;i<n;i++)
  	{
  		a=rr(MAXN);
  		fout<<a<<' ';
		}
		fout<<endl;
		for(i=0;i<m;i++)
		{
			o=rr(3);
			x=rr(n);
			for(y=0;y<x;y=rr(n));
			fout<<o<<' '<<x<<' '<<y<<' ';
			if(o==3)
			{
				fout<<endl;
			}
			else
			{
				o=rr(MAXN);
				fout<<o<<' '<<endl;
			}
		}
		fout.close();
		start=clock();
		system("A.exe <data.in >A.out");
		end=clock();
		system("B.exe <data.in >B.out");
		llf=clock();
		total+=llf-start;
		if(system("fc A.out B.out"))
		{
			cout<<"Wrong Answer on No."<<t<<" !!!"<<endl;
			system("pause");
		}
		else
		{
			cout<<"Accepted  +"<<end-start<<"ms		LLf:+"<<llf-end<<"ms		ÄúÀÛ¼ÆXuÁË"<<total/1000<<"s"<<endl;
			/*if(end-start<=llf-end)
			{
				cout<<"@@@___@@@"<<endl;
				system("pause");
			}*/
		}
  }
  return 0;
}
int rr(int x)
{
  return (long long)rand()*rand()%x+1;
}
