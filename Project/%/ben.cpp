#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
using namespace std;
char a[200];
int n=0;
int main()
{
  int i=0,j=0;
  srand(time(NULL));
  cin>>a;
  for(n=rand()%(strlen(a)>>3)+1;n--;)
  {
  	i=rand()%(strlen(a)>>1);
  	j=rand()%(strlen(a)>>1);
  	i<<=1;
  	j<<=1;
  	swap(a[i],a[j]);
  	swap(a[i+1],a[j+1]);
  }
  cout<<a<<endl;
  main();
  return 0;
}
