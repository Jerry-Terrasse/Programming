#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<sstream>
//E:\DAY-1\SC-Senior\answers\SC-0001\money\money.cpp
using namespace std;
stringstream sio;
string na1[3]={"road\\road.cpp ","money\\money.cpp ","track\\track.cpp "};
string na2[3]={"travel\\travel.cpp ","game\\game.cpp ","defense\\defense.cpp "};
string to1[3]={"road.cpp","money.cpp","track.cpp"};
string to2[3]={"travel.cpp","game.cpp","defense.cpp"};
string head1="copy E:\\DAY-1\\SC-Senior\\answers\\";
string head3="copy E:\\DAY-2\\SC-Senior\\answers\\";
string head2="E:\\emm\\";
string str="";
string work="";
int main()
{
  register int i=0,j=0;
  for(i=1;i<=852;++i)
  {
  	cout<<i<<endl;
	sio.str("");
  	sio.clear();
  	sio<<"SC-"<<setw(4)<<setfill('0')<<i<<"\\";
  	sio>>str;
  	work="md E:\\emm\\";
  	work+=str;
  	system(work.c_str());
  	for(j=0;j<3;++j)
  	{
  	  work=head1+str+na1[j];
  	  work+=head2+str+to1[j];
  	  cout<<work<<endl;
  	  system(work.c_str());
  	}
  	for(j=0;j<3;++j)
  	{
  	  work=head3+str+na2[j];
  	  work+=head2+str+to2[j];
  	  //cout<<work<<endl;
  	  system(work.c_str());
  	}
  }
  return 0;
}
