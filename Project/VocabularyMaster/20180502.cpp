#include<iostream>
#include<vector>
#include<fstream>
#include<exception>
#include<sstream>
#include<cstdlib>
using namespace std;
int load();
int extract(string&,string&);
int extract(string&,int&);
void posthumous();
struct word
{
  string ppt;//porperty
  int pfs;//prf.size
  vector<string>prf;//paraphrase
  int input();
};
struct group
{
  int index;
  int mbs;//member.size
  string name;
  //string pncE,pncA;//pronunciation
  string rmk;//remark
  vector<word>member;
  int input();
};
//group dft;//default
int amt=0;//amount
int exitingcode=0;
string cmd="";//command
vector<group>lbr;//library
ifstream fin("a.dll");
ofstream fout("z.dll");
stringstream wst;//workstation
int main()
{
  atexit(posthumous);
  try
  {
    load();
    /*for(;;)
    {
      
	}
    cin>>cmd;*/
  }
  catch(string error)
  {
    string err=error;
	switch(err[0])
    {
      case '~':
        cout<<"'#' not found in {"<<err<<"}"<<endl;
        break;
      case '!':
      	cout<<"'$$' not found in {"<<err<<"}"<<endl;
      	break;
      case '@':
      	cout<<"'$$$$' not found in {"<<err<<"}"<<endl;
      	break;
      case '%':
      	cout<<"'$$$$$$' not found in {"<<err<<"}"<<endl;
      	break;
      default:
        cout<<"Unknown Error in {"<<err<<"}"<<endl;
        break;
    }
    //emergencily do something
    exit(exitingcode=(int)err[0]);
  }
  return 0;
}
int load()
{
  int i=0;
  string ln;
  group a;
  fin>>ln;
  extract(ln,amt);
  //cout<<amt<<endl;
  for(i=0;i<amt;i++)
  {
    a.input();
    lbr.push_back(a);
  }
  
  return 0;
}
int group::input()
{
  int i=0;
  string ln="";
  word a;
  fin>>ln;
  extract(ln,index);
  fin>>ln;
  if((ln[0]=='$')&&(ln[1]=='$'))
  {
  	ln.erase(0,2);
  	extract(ln,name);
    //extract(ln,pncE);
    //extract(ln,pncA);
    extract(ln,mbs);
  	for(i=0;i<mbs;i++)
  	{
  	  a.input();
  	  member.push_back(a);
	}
  }
  else
  {
	ejecting:;
	string err="!";
  	err+="{";err+=ln;err+="}";
	throw err;
	return 2;
  }
  //cout<<"''''''''"<<member[0].ppt<<endl;
  fin>>ln;
  if((ln[0]=='$')&&(ln[1]=='$'))
  {
  	ln.erase(0,2);
	extract(ln,rmk);
  }
  else
  {
  	goto ejecting;
  }
  return 0;
}
int word::input()
{
  int i=0;
  string ln="";
  string a="";
  fin>>ln;
  if((ln[0]=='$')&&(ln[1]=='$')&&(ln[2]=='$')&&(ln[3]=='$'))
  {
    ln.erase(0,4);
    extract(ln,ppt);extract(ln,pfs);
    for(i=0;i<pfs;i++)
    {
      fin>>ln;
	  if((ln[0]=='$')&&(ln[1]=='$')&&(ln[2]=='$')&&(ln[3]=='$')&&(ln[4]=='$')&&(ln[5]=='$'))
      {
      	ln.erase(0,6);
      	extract(ln,a);
      	prf.push_back(a);
	  }
	  else
	  {
	  	string err="%";
	  	err+="{";err+=ln;err+="}";
	  	throw err;
	  	return 4;
	  }
	}
  }
  else
  {
	string err="@";
  	err+="{";err+=ln;err+="}";
	throw err;
	return 3;
  }
  return 0;
}
int extract(string& ln,string& data)
{
  wst.str("");
  wst.clear();
  if(ln[0]!='#')
  {
    ejecting:;
	string err="~";
    err+="{";err+=ln;err+="}";
	throw err;
	return 1;
  }
  ln.erase(0,1);
  for(;ln[0]!='#';ln.erase(0,1))
  {
	if(ln[0]=='\0')
	{
	  goto ejecting;
	}
	wst<<ln[0];
	//cout<<endl<<"{"<<wst.str()<<"}"<<endl;
  }
  ln.erase(0,1);
  wst>>data;
  return 0;
}
int extract(string& ln,int& data)
{
  wst.str("");
  wst.clear();
  if(ln[0]!='#')
  {
    ejecting:;
	string err="~";
    err+="{";err+=ln;err+="}";
	throw err;
	return 1;
  }
  ln.erase(0,1);
  for(;ln[0]!='#';ln.erase(0,1))
  {
	if(ln[0]=='\0')
	{
	  goto ejecting;
	}
	wst<<ln[0];
	//cout<<endl<<"{"<<wst.str()<<"}"<<endl;
  }
  ln.erase(0,1);
  wst>>data;
  return 0;
}
void posthumous()
{
  if(exitingcode)
  {
    cout<<"Exit With::::"<<exitingcode<<endl;
    system("pause");
  }
  return;
}
/*exceptions:
"~...": '#' not found in ...;
"!...": '$$' not found in ...;
"@...": '$$$$' not found in ...;
"%...": '$$$$$$' not found in ...;
*/
