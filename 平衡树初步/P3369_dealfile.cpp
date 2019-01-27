#include<iostream>
#include<fstream>
using namespace std;
int n=0;
ifstream fin;
ofstream fout;
int main()
{
  register int i=0,o=0,x=0;
  fin.open("P3369#5.in");
  fout.open("P3369.in");
  fin>>n;
  for(i=1;i<=n;++i)
  {
    fin>>o>>x;
    if(o>=3)
    {
      fout<<o<<' '<<x<<endl;
    }
  }
  return 0;
}