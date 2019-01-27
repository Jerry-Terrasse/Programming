#include<bits/stdc++.h>
#define MAXN 10
using namespace std;
int a=0,n=0,t=0;
ofstream fout;
int rr(int);
int main()
{
  int i=0;
  srand(time(NULL));
  for(;;t++)
  {
  	cout<<"No."<<t<<":"<<endl;
  	fout.open("P1880.in");
  	n=rr(MAXN)+1;
  	fout<<n<<endl;
  	for(i=0;i<n;i++)
  	{
  	  a=rr(MAXN);
  	  fout<<a<<" ";
	}
	fout<<endl;
	fout.close();
	system("P1880.exe <P1880.in >P1880.out");
	system("temp.exe <P1880.in >P1880.ans");
	if(system("fc P1880.out P1880.ans"))
	{
	  cout<<"Wrong Answer on No."<<t<<endl;
	  system("notepad P1880.in");
	  system("pause");
	}
	else
	{
	  cout<<"Accepted."<<endl;
	}
  }
  return 0;
}
int rr(int x)
{
  return rand()*rand()%x;
}
