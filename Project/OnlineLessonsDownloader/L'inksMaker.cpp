//http://live3.aijianzi.com/record/aijianzi/2018-03-17/5556_1/1521280341_13.ts
#include<bits/stdc++.h>
using namespace std;
//string f="";
//string t[2]={"working(","worked("};
string a="";//="http://live3.aijianzi.com/record/aijianzi/2018-03-17/5556_1/";
string s="";
int main()
{
  //cout<<"FileIndex:";
	//cin>>f;
	ifstream fin("G:\\Programing\\Project\\OnlineLessonsDownloader\\working.txt");
	ofstream fout("G:\\Programing\\Project\\OnlineLessonsDownloader\\worked.txt");
	if((!fin)||(!fout))
	{
	  cout<<"Fail to open files!"<<endl;
	  return 255;
	}
	cout<<"Host:";
	cin>>a;
	/*f+=").txt";
  t[0]+=f;t[1]+=f;
  cout<<endl<<t[0].c_str()<<endl<<t[1].c_str()<<endl;
  char tp0[20],tp1[20];
  //tp0[20]=t[0].c_str();
  strcpy(tp0,t[0].c_str());strcpy(tp1,t[1].c_str());
	const char* temp[2]={tp0,tp1};*/
	/*freopen("working.txt","r",stdin);
  freopen("worked.txt","w",stdout);*/
  while(fin>>s)
  {
  	if(-1!=s.find(".ts"))
  	{
  	  fout<<a<<s<<endl;
	  }
  }
  /*fclose(stdin);
  fclose(stdout);*/
  cout<<"Done"<<endl;
  system("pause");
  return 0;
}
