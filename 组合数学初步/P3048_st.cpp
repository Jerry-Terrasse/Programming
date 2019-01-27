#include<iostream>
#include<fstream>
using namespace std;
ofstream fout;
int main()
{
  register int i=0;
  for(i=1;i<=100;++i)
  {
    fout.open("P3048.in");
    fout<<i<<" 3"<<endl;
    fout.close();
    system("P3048.exe <P3048.in >>P3048_st.txt");
  }
  return 0;
}