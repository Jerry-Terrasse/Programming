#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
using namespace std;
int main()
{
  int s[4],e[4],t=0;
  for(;;++t)
  {
    cout<<t<<':'<<endl;
    system("./da >c.in");
    system("time ./1 <c.in >c.1");
    system("time ./2 <c.in >c.2");
    //system("time ./bf <c.in >c.bf");
    system("time ./c_set <c.in >c.set");
    if(system("diff c.1 c.2")||system("diff c.2 c.set")||system("diff c.set c.set"))
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
