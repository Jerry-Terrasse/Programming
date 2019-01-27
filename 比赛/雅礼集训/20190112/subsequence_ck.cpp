#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
  register int t=0;
  for(;;++t)
  {
    cout<<t<<endl;
    system("subsequence_da.exe >subsequence.in");
    system("subsequence_beta.exe <subsequence.in >subsequence.out");
    system("subsequence_b.exe <subsequence.in >subsequence.ans");
    if(system("fc subsequence.out subsequence.ans"))
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