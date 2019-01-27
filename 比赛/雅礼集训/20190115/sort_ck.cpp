#include<iostream>
using namespace std;
int main()
{
  register int t=0;
  for(;;++t)
  {
    cout<<t<<endl;
    system("sort_da.exe >sort.in");
    system("sort_bf.exe <sort.in >sort.ans");
    system("sort_tst.exe <sort.in >sort.out");
    if(system("fc sort.out sort.ans"))
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