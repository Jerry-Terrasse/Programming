#include<iostream>
#include<ctime>
#include<cstdio>
using namespace std;
int main()
{
  register int t=0,s=0,e=0;
  for(;;++t)
  {
    cout<<t<<endl;
    system("sequence_da.exe >sequence.in");
    //system("sequence_bf.exe <sequence.in >sequence.ans");
    s=clock();
    system("sequence_b.exe <sequence.in >sequence.out");
    e=clock();
    if(system("fc sequence.out sequence.ans"))
    {
      cout<<e-s<<"ms"<<endl;
      system("pause");
    }
    else
    {
      cout<<"AC "<<e-s<<"ms"<<endl;
    }
  }
}