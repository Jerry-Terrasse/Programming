#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
ifstream fin;
ofstream fout;
string s="",pre="http://live3.aijianzi.com/record/aijianzi/";
int main()
{
  int i=0;
  fin.open("#6.m3u8");
  fout.open("#6.txt");
  for(;fin>>s;)
  {
  	if(s[0]=='.')
  	{
  	  s.erase(0,6);
  	  fout<<pre+s<<endl;
	}
  }
  fin.close();
  fout.close();
  return 0;
}
