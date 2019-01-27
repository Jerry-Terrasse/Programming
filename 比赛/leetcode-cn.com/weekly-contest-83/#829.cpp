#include<iostream>
using namespace std;
class Solution
{
  public:
  int consecutiveNumbersSum(int N)
  {
    int i=0,k=0,m=0,s=0;
    for(i=1;i<=N;i++)
    {
      for(k=1;(m=(2*i+k-1)*k/2)<=N;s+=(m==N),k++);
    }
    return s;
  }
};
int main()
{
  int N=0;
  Solution kkkk;
  cin>>N;
  cout<<(N=kkkk.consecutiveNumbersSum(N));
}
