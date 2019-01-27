#include<iostream>
using namespace std;
int main()
{
  register int t=0;
  for(;;++t)
  {
    cout<<t<<endl;
    system("P1196_da.exe >P1196.in");
    system("P1196_ans.exe <P1196.in >P1196.ans");
    system("P1196.exe <P1196.in >P1196.out");
    if(system("fc P1196.out P1196.ans"))
    {
      system("pause");
      system("pause");
    }
    else
    {
      cout<<"AC"<<endl;
    }
  }
  return 0;
}