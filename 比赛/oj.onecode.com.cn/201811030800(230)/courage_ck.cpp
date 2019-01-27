#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	register int t=0,e=0,s=0;
	for(;; ++t)
	{
		cout<<"No."<<t<<endl;
		system("courage_da.exe >courage.in");
		system("courage_bf.exe <courage.in >courage.ans");
		if(!system("fc courage.ans empty.txt"))
		{
			continue;
		}
		s=clock();
		system("courage.exe <courage.in >courage.out");
		e=clock();
		if(system("fc courage.out courage.ans"))
		{
			system("pause");
			system("pause");
		}
		else
		{
			cout<<"AC "<<e-s<<endl;
		}
	}
	return 0;
}
