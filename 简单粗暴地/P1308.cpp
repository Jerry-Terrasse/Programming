#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string lowercase(string);
int main()
{
 bool b=0;
 char c='\0';
 string temp="";
 char tt=' ';
 string input="";
 int i=1,j=0,k=0,count=0,f=0,ining=0;
 string s[10000];
 string a="";
 /*for(i=0;i<=9999;i++)
 {
   s[i]="j";
 }
 i=1;*/
 cin>>a;
 //gets(a);
 //a[a.length()]='/0';
 //gets(input);
 getline(cin,input);
 getline(cin,input);
 //cout<<"{"<<a<<"}"<<"{"<<input<<"}"<<endl;
 //cout<<(int)a[2]<<endl;
 //cin>>input;
 /*while(tt!='13')
 {
   cin>>tt;
   input+=tt;
 }*/
 a=lowercase(a);
 do
 {
  c=input[ining];
  ining++;
  if((c==' ')||(c==13)||(c==32))
   {
   b=true;
   i++;
   s[i]=' ';
   }
  else
   {
   if(b)
    {
    b=false;
    i++;
    }
   temp=c;
   s[i]+=lowercase(temp);
   }
 }while(c!='\0');
 /*int kkkkk=0;
 for(kkkkk=0;kkkkk<=30;kkkkk++)
 {
   cout<<"{"<<s[kkkkk]<<"}"<<endl;
 }*/
 //cout<<"{"<<a<<"}"<<endl;
 //cout<<input<<endl;
 i--;
 f=-1;
 for(j=0;j<=i-1;j++)//
  {
  if(s[j]==a)
   {
   if(f==-1)
    {
    for(k=1;k<=j-1;k++)
     {
     	f+=s[k].length();
	 }
    f++;
    }
   count++;
   }
  }
 if(f==-1)
 {
   cout<<"-1"<<endl;
 }
 else
 {
   cout<<count<<" "<<f<<endl;
 }
 return 0;
}
string lowercase(string a)
{
  int i=0;
  string s=a;
  for(i=0;s[i]!='\0';i++)
  {
  	if((65<=s[i])&&(s[i]<=90))
  	{
  	  s[i]+=32;
	}
  }
  return s;
}
