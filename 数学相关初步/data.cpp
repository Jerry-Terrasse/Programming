#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
#define rand() abs(rand())
using namespace std;
int main()
{
  int n=0,a=0,b=0,m=0;
  cin>>n;
  cout<<n<<endl;
  srand(time(NULL));
  for(int i=0;i<n;i++)
  {
    a=rand()+1;b=rand()+1;m=rand()+1;
    cout<<a<<' '<<b<<' '<<m<<endl;
  }
  return 0;
}
