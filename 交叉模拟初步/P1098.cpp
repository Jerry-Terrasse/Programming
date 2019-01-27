#include<iostream>
#include<string>
#define maxn
using namespace std;
int main(){
	int p1,p2,p3;
	string s;
	cin>>p1>>p2>>p3;
//
    cin>>s;
	for(int i=0;i<s.length();i++)
		{
		if(s[i]!='-')cout<<s[i];
		else if((i==0 || i==s.length()-1) && s[i]=='-')cout<<s[i];
		else if(s[i]=='-' && (s[i-1]=='-' || s[i+1]=='-'))cout<<s[i];
		else if(s[i]=='-' && s[i-1]==s[i+1])cout<<s[i];
		else if(s[i]=='-')
		{
			if(s[i-1]>s[i+1] || (s[i-1]<58 && s[i+1]>96))cout<<s[i];
			else if(s[i+1]==s[i]+1)continue;
			else{
			if(p3==1)
			for(int j=(int)s[i-1]+1;j<(int)s[i+1];j++)
			for(int k=0;k<p2;k++){
			if(p1==3)cout<<'*';
			else if(p1==1)cout<<(char)j;
			else cout<<(char)(j-32);
			}
			else
			for(int j=(int)s[i+1]-1;j>(int)s[i-1];j--)
			for(int k=0;k<p2;k++){
			if(p1==3)cout<<'*';
			else if(('0'<=j)&&(j<='9'))cout<<(char)j;
			else if(p1==1)cout<<(char)j;
			else cout<<(char)(j-32);
			}
			}
		}
	}
	return 0;
}
