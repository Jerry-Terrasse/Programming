#include<iostream>
#include<vector>
#include<fstream>
#include<exception>
#include<sstream>
#include<cstdlib>
using namespace std;
int main();
int load();
int extract(string&,string&);
int extract(string&,int&);
int simplify(string&,string);
int simplify(string&,string,string);
int crtid(string);//create index
int save();
int work();
int add();
int mns();//minus
void posthumous();
struct word
{
  string ppt;//porperty
  int pfs;//prf.size
  vector<string>prf;//paraphrase
  int load();
  int ipt();//input from cin
};
struct group
{
  int index;
  int mbs;//member.size
  string name;
  //string pncE,pncA;//pronunciation
  string rmk;//remark
  vector<word>member;
  int load();
  int ipt();//input from stringstream wst
};
group g_dft;//default of group
word w_dft;//defalt of word
int amt=0;//amount||lbr.size()
int exitingcode=0;
string cmd="";//command
vector<group>lbr;//library
ifstream fin;
ofstream fout;
stringstream wst;//workstation
int main()
{
  atexit(posthumous);
  try
  {
    load();
    for(;;)
    {
	  cout<<"\\>";
      if(getline(cin,cmd,'\n'))
      {
		work();
	  }
	  else
	  {
	  	string err="^";
	    err+="{";err+="";err+="}";
	    throw err;
	    return 5;
	  }
    }
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
      case '^':
      	cout<<"fail to input in {"<<err<<"}"<<endl;
      	break;
      case '&':
      	cout<<"fail to open file in {"<<err<<"}"<<endl;
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
  g_dft.index=0;
  g_dft.mbs=0;
  g_dft.name="";
  g_dft.rmk="";
  w_dft.ppt="";
  w_dft.pfs=0;
  group a=g_dft;
  fin.open("a.dll",ios::in);
  if(!fin.is_open())
  {
  	string err="&";
  	err+="{";err+="fin.open(\"a.dll\",ios::in);";err+="}";
  	throw err;
  }
  fin>>ln;
  extract(ln,amt);
  //cout<<amt<<endl;
  for(i=0;i<amt;i++)
  {
    a.load();
    lbr.push_back(a);
  }
  fin.close();
  return 0;
}
int group::load()
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
  	  a.load();
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
int group::ipt()
{
  int i=0;
  bool bo=false;//word is set
  bool w_exist=false;//word is exist
  string ln="";
  word nwd=w_dft;//new word
  getline(cin,ln,'\n');
  simplify(ln," ");
  name=ln;
  index=crtid(name);
  for(;getline(cin,ln,'\n');)//set <word>member & rmk
  {
  	if('#'==ln[0])
  	{
  	  break;
	}
	if(('a'>ln[0])||(ln[0]>'z'))
	{
	  if(bo)
	  {
	  	rmk+="|";
	  	rmk+=ln;
	  }
	  continue;
	}
	simplify(ln,"£»",";");
	ln+=";";
    wst.str("");
    wst.clear();
	wst<<ln;
	nwd.ipt();
	bo=true;
	w_exist=false;
	for(;i<mbs;i++)
	{
	  if(member[i].ppt==nwd.ppt)
	  {
	  	w_exist=true;
	  	break;
	  }
	}
	if(w_exist)
	{
	  //do with member[i]
	}
	else
	{
	  member.push_back(nwd);
	  mbs++;
	}
  }
  return 0;
}
int word::load()
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
int word::ipt()
{
  wst>>ppt;
  string npf="";//new prf
  for(;getline(wst,npf,';');)
  {
  	prf.push_back(npf);
  	pfs++;
  }
  return 0;
}
int save()
{
  //
  return 0;
}
int work()
{
  simplify(cmd," ");
  simplify(cmd,"\t");
  if(cmd=="add")
  {
    cout<<"  "<<"adding"<<endl;
	add();
	return 0;
  }
  else if(cmd=="minus")
  {
  	cout<<"  "<<"minusing"<<endl;
	mns();
    return 0;
  }
  else if(cmd=="save")
  {
  	cout<<"  "<<"saving"<<endl;
	save();
	return 0;
  }
  else if(cmd=="exit")
  {
  	cout<<"  "<<"exiting"<<endl;
	exit(0);
	return 0;
  }
  else if(cmd=="")
  {
  	return 0;
  }
  else
  {
    cout<<"  "<<"Unknown Comand"<<endl;
    return 0;
  }
  return 0;
}
int add()
{
  int i=0;
  bool exist=false;
  group ngp=g_dft;//new group
  cout<<"  "<<"Paste blow:"<<endl;
  ngp.ipt();
  for(;i<amt;i++)
  {
  	if(lbr[i].index==ngp.index)
  	{
  	  exist=true;
  	  break;
	}
  }
  if(exist)
  {
  	//do by existing
  	//
  	//
  	//
  }
  else
  {
  	lbr.push_back(ngp);
  	amt++;
  }
  return 0;
}
int mns()
{
  //Your code puts here;
  cout<<"  "<<"No!!!"<<endl;
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
int simplify(string& ln,string trash)
{
  int sward=0;
  for(;-1!=(sward=ln.find(trash));ln.erase(sward,trash.length()));
  return 0;
}
int simplify(string& ln,string trash,string gem)
{
  int sward=0;
  for(;-1!=(sward=ln.find(trash));ln.replace(sward,trash.length(),gem));
  return 0;
}
int crtid(string name)
{
  
  return 0;
}
void posthumous()
{
  save();
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
"^...": fail to read in ...;
*/
