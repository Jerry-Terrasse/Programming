#include<iostream>
using namespace std;
const string w[5]={"23","03","14","24","01"};
int main()
{
  int n=0,na=0,nb=0,i=0,j=0,sa=0,sb=0,ak=0,bk=0;
  bool bo=false;
  cin>>n>>na>>nb;
  int a[na],b[nb];
  for(i=0;i<=na-1;i++)
  {
  	cin>>a[i];
  }
  for(i=0;i<=nb-1;i++)
  {
  	cin>>b[i];
  }
  for(i=0;i<=n-1;i++)
  {
    ak=a[i%na];bk=b[i%nb];
    //cout<<i<<"--"<<ak<<"Vs"<<bk<<":";
    if(ak!=bk)
    {
      bo=false;
	  for(j=0;j<=1;j++)
      {
      	if(w[ak][j]==bk+'0')
      	{
      	  bo=true;
      	  break;
		}
	  }
	  if(bo)
	  {
	  	sa++;
	  	//cout<<"sa"<<endl;
	  }
	  else
	  {
	  	sb++;
	  	//cout<<"sb"<<endl;
	  }
	}
  }
  cout<<sa<<" "<<sb<<endl;
  return 0;
}
