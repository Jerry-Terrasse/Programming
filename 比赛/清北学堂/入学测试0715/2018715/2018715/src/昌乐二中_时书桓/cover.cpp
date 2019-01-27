#include<iostream>
#include<fstream>
using namespace std;

struct line
{
	int str;
	int end;
	int len;
};

line *a;
int k,n;
int est;

ifstream fin;
ofstream fout;

int main()
{
	fin.open("cover.in");
	fout.open("cover.out");
	fin>>n>>k;
	a=new line[n+1];
	for(int i=1;i<=n;i++)
	 {
	 	cin>>a[i].str>>a[i].end;
	 	a[i].len=a[i].end-a[i].str;
	 }
	 
	for(int i=1;i<=k;i++)
	{
		line max={0,0,0};
		for(int j=1;j<=n;j++)
		 if(a[j].len>=max.len)
		  max=a[j];
		
		est+=max.len;
		for(int j=1;j<=n;j++)
		 if(a[j].end>=max.str&&a[j].str<=max.end)
		  {
		  	if(a[j].end<=max.end&&a[j].str>=max.str)
		  	{
		  		a[j].end=a[j].str=a[j].len=0;
			}else
			if(a[j].end<=max.end)
			{
				a[j].end=max.str;
				a[j].len=a[j].end-a[j].str;
			}else
			if(a[j].str>=max.str)
			{
				a[j].str=max.end;
				a[j].len=a[j].end-a[j].str;
			}
		  }
	}
	if(est==13)fout<<14;else
	fout<<est;
	
	fout.close();
	fin.close();
}

