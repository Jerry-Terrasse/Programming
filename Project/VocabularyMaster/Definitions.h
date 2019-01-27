int main();
int load();
int extract(string&,string&);
int extract(string&,int&);
int simplify(string&,string);
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
group g_dft;//default of group
word w_dft;//defalt of word
int amt=0;//amount
int exitingcode=0;
string cmd="";//command
vector<group>lbr;//library
ifstream fin;
//ofstream fout("z.dll");
stringstream wst;//workstation