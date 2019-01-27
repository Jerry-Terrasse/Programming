#include<iostream>
#include<ctime>
#include<cstdilb>
#include<cstdio>
using namespace std;
int main()
{
  int t=0;
  for(;;++t)
  {
    cout<<t<<':'<<endl;
    system("./da >c.in");
    system("./1 <c.in >c.1");
    system("./2 <c.in >c.2");
    system("./bf <c.in >c.bf");
    system("./c_set <c.in >c.set");
    if(system("diff c.1 c.2")||system("diff c.2 c.bf")||system("diff c.bf c.set"))
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
