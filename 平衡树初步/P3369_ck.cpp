#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
  register int t=0;
  for(;;++t)
  {
    cout<<t<<endl;
    system("P3369_da.exe");
    system("P3369.exe <P3369.in >P3369.out");
    if(system("fc P3369.out P3369.ans"))
    {
      system("pause");
    }
    else
    {
      cout<<"AC"<<endl;
    }
  }
  return 0;
}