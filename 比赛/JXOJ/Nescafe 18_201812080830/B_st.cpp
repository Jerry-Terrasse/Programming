#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
ofstream fout;
int main()
{
  register int i=0;
  for(i=2;i<=11;++i)
  {
    fout.open("B.in");
    fout<<i<<endl;
    fout.close();
    system("echo ''' >>B_st.py");
    system("B.exe <B.in >>B_st.py");
    system("echo ''', >>B_st.py");
  }
  return 0;
}