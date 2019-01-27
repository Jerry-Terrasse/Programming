#include<cstdlib>
#include<iostream>
#include<fstream>
using namespace std;
ofstream fout;
int main()
{
  register int i=0;
  for(i=1;i<=18;++i)
  {
    cout<<i<<endl;
    fout.open("data.txt");
    fout<<i<<endl;
    fout.close();
    //system("dir");
    system("P1044.exe <data.txt >>P1044_st.txt");
  }
  return 0;
}