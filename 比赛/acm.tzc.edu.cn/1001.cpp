#include<iostream>
#include<sstream>
#define tn TreeNode
using namespace std;
  struct tn {
  int val;
  struct tn *left;
  struct tn *right;
};
tn* mergeTrees(tn*,tn*);
stringstream sin;
int main()
{
  string ln;
  int n[2]={1,1},i=0,j=0;
  for(j=0;j<=1;j++)
  {
    getline(cin,ln,'\n');
    sin<<ln<<endl;
    for(;-1!=(i=ln.find(" "));n[j]++,ln.erase(i,1));
  }
  
  return 0;
}
tn* mergeTrees(tn* t1,tn* t2)
{
  *t1.val+=*t2.val;
  
}
