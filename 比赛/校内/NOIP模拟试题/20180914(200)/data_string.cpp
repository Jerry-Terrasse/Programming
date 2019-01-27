#include<bits/stdc++.h>
using namespace std;
int main()
{
  int i=0;
  srand(time(NULL));
  for(i=0;i<100000;i++)
  {
  	cout<<(rand()%2?'a':'b');
  }
  cout<<endl;
  for(i=0;i<100;i++)
  {
  	cout<<(rand()%2?'a':'b');
  }
  cout<<endl;
  return 0;
}
