#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
#include<sstream>
using namespace std;
ofstream fout;
stringstream sio;
int main()
{
  int i=0,j=0;
  string s="";
  for(i=1;i<=8;i++)
  {
  	for(j=1;j<=8;j++)
  	{
  	  fout.open("chess.in");
  	  fout<<i<<' '<<j<<endl;
  	  fout.close();
  	  system("chess.exe <chess.in >>sheet.txt");
  	  sio<<"echo "<<"\"=="<<i<<','<<j<<"\" >>sheet.txt"<<endl;
  	  getline(sio,s,'\n');
	  system(s.c_str());
	}
  }
  return 0;
}
